using GrpcFileReader.Services;
using Microsoft.Extensions.Logging;
using Moq;

namespace Test.GrpcFileReader;
public class FileProviderServiceTests
{
    private readonly Mock<ILogger<FileProviderService>> _mockLogger;
    private readonly FileProviderService _fileProviderService;

    public FileProviderServiceTests()
    {
        _mockLogger = new Mock<ILogger<FileProviderService>>();
        _fileProviderService = new FileProviderService(_mockLogger.Object);
    }

    [Fact]
    public void SetInputFile_ValidFilePath_SetsFilePath()
    {
        string filePath = "test.txt";
        _fileProviderService.SetInputFile(filePath);

        var filePathField = typeof(FileProviderService).GetField("_filePath", System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
        Assert.Equal(filePath, filePathField.GetValue(_fileProviderService));
    }

    [Fact]
    public void SetInputFile_NullOrEmptyFilePath_ThrowsArgumentException()
    {
        // Arrange
        string filePath = "";
        // Act
        Action act = () => _fileProviderService.SetInputFile(filePath);
        //Assert
        ArgumentException exception = Assert.Throws<ArgumentException>(act);
        Assert.Equal("File path cannot be empty or null", exception.Message);
    }

    [Fact]
    public void Init_FilePathNotSet_ThrowsInvalidOperationException()
    {
        // Act
        Action act = () =>  _fileProviderService.Init();
        // Assert
        InvalidOperationException exception = Assert.Throws<InvalidOperationException>(act);
        Assert.Equal("File path is not set yet", exception.Message);
    }

    [Fact]
    public void Init_FileStreamOpened_ReturnsTrue()
    {
        // Arrange
        string filePath = "test.txt";
        _fileProviderService.SetInputFile(filePath);

        // Using a temporary file for testing
        using (var tempFile = new TempFile())
        {
            _fileProviderService.SetInputFile(tempFile.FilePath);

            // Act
            var result = _fileProviderService.Init();

            // Assert
            Assert.True(result);
        }
    }

    [Fact]
    public void Dispose_FileStreamNotNull_DisposesFileStream()
    {
        // Arrange
        string filePath = "test.txt";
        _fileProviderService.SetInputFile(filePath);

        // Using a temporary file for testing
        using (var tempFile = new TempFile())
        {
            _fileProviderService.SetInputFile(tempFile.FilePath);
            _fileProviderService.Init();

            // Act
            _fileProviderService.Dispose();

            // Assert
            // Reflection is used here to access the private _fileStream field for testing
            var fileStreamField = typeof(FileProviderService).GetField("_fileStream", System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
            Assert.Null(fileStreamField.GetValue(_fileProviderService));
        }
    }

    [Fact]
    public void ReadByte_FileStreamNotInitialized_ThrowsInvalidOperationException()
    {
        // Act & Assert
        var ex = Assert.Throws<InvalidOperationException>(() => _fileProviderService.ReadByte(0));
        Assert.Equal("File stream is not initialized.", ex.Message);
    }

    [Fact]
    public void ReadByte_InvalidOffset_ThrowsEndOfStreamException()
    {
        // Arrange
        using (var tempFile = new TempFile())
        {
            _fileProviderService.SetInputFile(tempFile.FilePath);
            _fileProviderService.Init();

            // Act & Assert
            var ex = Assert.Throws<EndOfStreamException>(() => _fileProviderService.ReadByte(100));
            Assert.Equal("read 0 byte from file, EOF reached", ex.Message);
        }
    }

    [Fact]
    public void ReadByte_ValidOffset_ReturnsByte()
    {
        // Arrange
        using (var tempFile = new TempFile())
        {
            _fileProviderService.SetInputFile(tempFile.FilePath);
            _fileProviderService.Init();

            // Act
            byte result = _fileProviderService.ReadByte(0);
            byte result1 = _fileProviderService.ReadByte(3);

            // Assert
            Assert.Equal(tempFile.Content[0], result);
            Assert.Equal(tempFile.Content[3], result1);
        }
    }

    // Helper class to create a temporary file for testing
    private class TempFile : IDisposable
    {
        public string FilePath { get; }
        public byte[] Content { get; }

        public TempFile()
        {
            FilePath = Path.GetTempFileName();
            Content = new byte[] { 0x01, 0x02, 0x03, 0x04 };
            File.WriteAllBytes(FilePath, Content);
        }

        public void Dispose()
        {
            if (File.Exists(FilePath))
            {
                File.Delete(FilePath);
            }
        }
    }
}
