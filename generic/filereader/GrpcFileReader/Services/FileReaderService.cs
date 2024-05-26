using Grpc.Core;
using Google.Protobuf;

namespace GrpcFileReader.Services;

public class FileReaderService : GrpcFileReader.FileReaderService.FileReaderServiceBase {
    private readonly ILogger<FileReaderService> _logger;
    private readonly IProviderService _provider;
    public FileReaderService(
        ILogger<FileReaderService> logger,
        IProviderService provider) {
        _logger = logger;
        _provider = provider;
    }

    public override async Task GetFileBytes(
        GetFileBytesRequest request,
        IServerStreamWriter<GetFileBytesResponse> responseStream,
        ServerCallContext context) {
        byte[] buffer = new byte[16];
        long offset = 0;

        try {
            string filePath = request.InputString;
            _logger.LogInformation("Received request for file {" + filePath + "}");

            _provider.SetInputFile(filePath);
            _provider.Init();

            do
            {
                buffer[offset % 16] = _provider.ReadByte(offset);
                ++offset;

                if ((offset % 16) == 0) {
                    // Write the response to the responseStream
                    await responseStream.WriteAsync(new GetFileBytesResponse { Data = ByteString.CopyFrom(buffer) });
                }
            } while (true);
        }
        catch (EndOfStreamException e) {
            _logger.LogInformation("End of file reached" +  e.Message);

            byte[] newBuffer = new byte[offset % 16];
            Array.Copy(buffer, 0, newBuffer, 0, offset % 16);
            await responseStream.WriteAsync(new GetFileBytesResponse { Data = ByteString.CopyFrom(newBuffer) });
        }
        catch (Exception e) {
            _logger.LogError(e, "Failed to read file");
            throw new RpcException(new Status(StatusCode.Internal, e.Message), new Metadata());
        }
    }

    public override async Task GetFileNames(
        GetFileNamesRequest request,
        IServerStreamWriter<GetFileNamesResponse> responseStream,
        ServerCallContext context) {
    
        try {
            string[] files = _provider.ReadFileNames();
            foreach (string file in files) {
                await responseStream.WriteAsync(new GetFileNamesResponse { FileNames = file });
            }
        }
        catch (Exception e) {
            _logger.LogError(e, "Failed to read filenames");
            throw new RpcException(new Status(StatusCode.Internal, e.Message), new Metadata());
        }
    }

    

    /*
        public override async Task GetFileBytes(
        GetFileBytesRequest request,
        IServerStreamWriter<GetFileBytesResponse> responseStream,
        ServerCallContext context) {
        byte[] buffer = new byte[16];
        long offset = 0;

        try {
            string filePath = Path.Combine(Directory.GetCurrentDirectory(), "Data", request.InputString);
            _logger.LogInformation("Received request for file {" + filePath + "}");

            _provider.SetInputFile(filePath);
            _provider.Init();

            do
            {
                Task<byte>[] tasks = new Task<byte>[16];
                for (int i = 0; i < 16; i++) {
                    tasks[i] = _provider.ReadByte(offset + i);
                }
                await Task.WhenAll(tasks);
                for (int i = 0; i < 16; i++)
                {
                    buffer[i] = tasks[i].Result;
                }
                offset += 16;

                if ((offset % 16) == 0) {
                    // Write the response to the responseStream
                    await responseStream.WriteAsync(new GetFileBytesResponse { Data = ByteString.CopyFrom(buffer) });
                }
            } while (true);
        }
        catch (EndOfStreamException e) {
            _logger.LogInformation("End of file reached" +  e.Message);

            byte[] newBuffer = new byte[offset % 16];
            Array.Copy(buffer, 0, newBuffer, 0, offset % 16);
            await responseStream.WriteAsync(new GetFileBytesResponse { Data = ByteString.CopyFrom(newBuffer) });
        }
        catch (Exception e) {
            _logger.LogError(e, "Failed to read file");
            throw new RpcException(new Status(StatusCode.Internal, e.Message), new Metadata());
        }
    }*/
}
