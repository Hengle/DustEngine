cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(DustEngine VERSION 0.0.1)
message(STATUS "[Project] ${PROJECT_NAME}")

include(cmake/InitUCMake.cmake)
Ubpa_InitUCMake()

Ubpa_InitProject()

Ubpa_AddDep(URapidJSON  0.0.1)
Ubpa_AddDep(USTL        0.1.1)
Ubpa_AddDep(UDP         0.7.1)
Ubpa_AddDep(UGM         0.6.8)
Ubpa_AddDep(ULuaPP      0.1.4)
Ubpa_AddDep(UECS        0.11.2)
Ubpa_AddDep(UDXRenderer 0.0.3)

Ubpa_DownloadZip(
	https://cdn.jsdelivr.net/gh/Ubpa/UData@master/DustEngine/crossguid/crossguid_20200809.zip
	crossguid_20200809.zip
	SHA256 567663B30C1CEB24C8C9D815C1D60579A7CA9D3D3888702858EB2FD672E429B5
)

Ubpa_AddSubDirsRec(src)

Ubpa_Export(DIRECTORIES "include")
