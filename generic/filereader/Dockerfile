# Use the official .NET SDK image to build the app
FROM mcr.microsoft.com/dotnet/sdk:8.0 AS build
WORKDIR /source

# Copy the project file and restore dependencies
COPY GrpcFileReader/GrpcFileReader.csproj ./GrpcFileReader/
RUN dotnet restore ./GrpcFileReader/GrpcFileReader.csproj

# Copy the remaining files and build the app
COPY GrpcFileReader/. ./GrpcFileReader/
WORKDIR /source/GrpcFileReader
RUN dotnet publish -c Release -o /app --no-restore

# Use the official .NET runtime image to run the app
FROM mcr.microsoft.com/dotnet/aspnet:8.0 AS runtime
WORKDIR /app
COPY --from=build /app ./

# Expose the port and run the application
EXPOSE 80
ENTRYPOINT ["dotnet", "GrpcFileReader.dll"]
