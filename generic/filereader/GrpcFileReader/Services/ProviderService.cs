namespace GrpcFileReader.Services;

// Not so relevant, but created this to show possiblity of Interface usage.
// for easy 
public class IProviderService {
    public virtual void SetInputFile(string filePath) {
        throw new NotImplementedException();
    }
    public virtual bool Init() {
        throw new NotImplementedException();
    }
    public virtual void Dispose() {
        throw new NotImplementedException();
    }
    public virtual byte ReadByte(long offset) {
        throw new NotImplementedException();
    }

    public virtual string[] ReadFileNames() {
        throw new NotImplementedException();
    }

    /*public virtual Task<byte> ReadByte(long offset) {
        throw new NotImplementedException();
    }*/
}

public class FileProviderService : IProviderService {
    private readonly ILogger<FileProviderService> _logger;

    // filepath to be set when the grpc service gets a request to server
    private string? _filePath;

    // filestream to be opened when the init is called from grpc service is called
    private FileStream? _fileStream;

    private string _folderPath = Path.Combine(Directory.GetCurrentDirectory(), "Data");

    public FileProviderService(ILogger<FileProviderService> logger) {
        _logger = logger;
    }

    public override void SetInputFile(string filePath) {
        if (string.IsNullOrEmpty(filePath)) {
            _logger.LogCritical("File path cannot be empty or null");
            throw new ArgumentException("File path cannot be empty or null");
        }

        _filePath = filePath;
    }

    // Provider to open required handle to serve the data
    public override bool Init() {

        if (_filePath == null) {
            _logger.LogCritical("File path is not set yet");
            throw new InvalidOperationException("File path is not set yet");
        }
        try {
            string filePath = Path.Combine(_folderPath, _filePath);
            _fileStream = new FileStream(filePath, FileMode.Open, FileAccess.Read);
            _logger.LogInformation("File stream opened for file {" + filePath + "}");
        }
        catch (Exception e) {
            _logger.LogError(e, "Failed to open file stream");
            throw new InvalidOperationException("Failed to open file stream");
        }

        return true;
    }
    
    // Close/Dispose the file stream
    public override void Dispose() {
        if (_fileStream != null) {
            _fileStream.Dispose();
        }
        _fileStream = null; 
    }

    // Reads a sinlge byte from the file, throws EOF exception if offset is beyond limit
    public override byte ReadByte(long offset) {
        byte[] buffer = new byte[1];

        if (_fileStream != null) {
            int bytesRead = 0;
            try {
                _fileStream.Seek(offset, SeekOrigin.Begin);
                bytesRead = _fileStream.Read(buffer, 0, 1);
            }
            catch  (Exception e) {
                _logger.LogError(e, "Failed to read byte from file");
                throw new InvalidOperationException("Failed to read byte from file");
            }
            if (bytesRead == 1) {
                return buffer[0];
            }
            else {
                _logger.LogCritical("read 0 byte from file, EOF reached");
                throw new EndOfStreamException("read 0 byte from file, EOF reached");
            }
        }
        else {
            _logger.LogCritical("File stream is not initialized.");
            throw new InvalidOperationException("File stream is not initialized.");
        }
    }

    // Reads the file names from the directory
    public override string[] ReadFileNames() {
        string[] fileNames = Directory.GetFiles(_folderPath);
        if (fileNames.Length == 0) {
            throw new FileNotFoundException("No files found in the directory");
        }
        for (int i = 0; i < fileNames.Length; i++) {
            fileNames[i] = Path.GetFileName(fileNames[i]);
        }
        return fileNames;
    }

    /*
    // Reads a sinlge byte from the file, it can be called async using multiple thread
    // providing 
    public override Task<byte> ReadByte(long offset) {
        byte[] buffer = new byte[1];

        if (_fileStream != null) {
            int bytesRead = 0;
            try {
                _fileStream.Seek(offset, SeekOrigin.Begin);
                bytesRead = _fileStream.Read(buffer, 0, 1);
            }
            catch  (Exception e) {
                _logger.LogError(e, "Failed to read byte from file");
                throw new InvalidOperationException("Failed to read byte from file");
            }
            if (bytesRead == 1) {
                return Task.FromResult(buffer[0]);
            }
            else {
                _logger.LogCritical("read 0 byte from file, EOF reached");
                throw new EndOfStreamException("read 0 byte from file, EOF reached");
            }
        }
        else {
            _logger.LogCritical("File stream is not initialized.");
            throw new InvalidOperationException("File stream is not initialized.");
        }
    }
    */
}