@echo off
cd /D "D:\Github\GP-Project-1\out\build\x64-Debug (default)" || (set FAIL_LINE=2& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: uv.dll ..." || (set FAIL_LINE=3& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different D:/Github/GP-Project-1/cocos2d/external/uv/prebuilt/win32/uv.dll "D:/Github/GP-Project-1/out/build/x64-Debug (default)/bin/mygit2dx/uv.dll" || (set FAIL_LINE=4& goto :ABORT)
cd /D "D:\Github\GP-Project-1\out\build\x64-Debug (default)" || (set FAIL_LINE=5& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: libssl-1_1.dll ..." || (set FAIL_LINE=6& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different D:/Github/GP-Project-1/cocos2d/external/openssl/prebuilt/win32/libssl-1_1.dll "D:/Github/GP-Project-1/out/build/x64-Debug (default)/bin/mygit2dx/libssl-1_1.dll" || (set FAIL_LINE=7& goto :ABORT)
cd /D "D:\Github\GP-Project-1\out\build\x64-Debug (default)" || (set FAIL_LINE=8& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: libcrypto-1_1.dll ..." || (set FAIL_LINE=9& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different D:/Github/GP-Project-1/cocos2d/external/openssl/prebuilt/win32/libcrypto-1_1.dll "D:/Github/GP-Project-1/out/build/x64-Debug (default)/bin/mygit2dx/libcrypto-1_1.dll" || (set FAIL_LINE=10& goto :ABORT)
cd /D "D:\Github\GP-Project-1\out\build\x64-Debug (default)" || (set FAIL_LINE=11& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: websockets.dll ..." || (set FAIL_LINE=12& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different D:/Github/GP-Project-1/cocos2d/external/websockets/prebuilt/win32/websockets.dll "D:/Github/GP-Project-1/out/build/x64-Debug (default)/bin/mygit2dx/websockets.dll" || (set FAIL_LINE=13& goto :ABORT)
cd /D "D:\Github\GP-Project-1\out\build\x64-Debug (default)" || (set FAIL_LINE=14& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: libcurl.dll ..." || (set FAIL_LINE=15& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different D:/Github/GP-Project-1/cocos2d/external/curl/prebuilt/win32/libcurl.dll "D:/Github/GP-Project-1/out/build/x64-Debug (default)/bin/mygit2dx/libcurl.dll" || (set FAIL_LINE=16& goto :ABORT)
cd /D "D:\Github\GP-Project-1\out\build\x64-Debug (default)" || (set FAIL_LINE=17& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: sqlite3.dll ..." || (set FAIL_LINE=18& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different D:/Github/GP-Project-1/cocos2d/external/sqlite3/libraries/win32/sqlite3.dll "D:/Github/GP-Project-1/out/build/x64-Debug (default)/bin/mygit2dx/sqlite3.dll" || (set FAIL_LINE=19& goto :ABORT)
cd /D "D:\Github\GP-Project-1\out\build\x64-Debug (default)" || (set FAIL_LINE=20& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: glew32.dll ..." || (set FAIL_LINE=21& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different D:/Github/GP-Project-1/cocos2d/external/win32-specific/gles/prebuilt/glew32.dll "D:/Github/GP-Project-1/out/build/x64-Debug (default)/bin/mygit2dx/glew32.dll" || (set FAIL_LINE=22& goto :ABORT)
cd /D "D:\Github\GP-Project-1\out\build\x64-Debug (default)" || (set FAIL_LINE=23& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: iconv.dll ..." || (set FAIL_LINE=24& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different D:/Github/GP-Project-1/cocos2d/external/win32-specific/icon/prebuilt/iconv.dll "D:/Github/GP-Project-1/out/build/x64-Debug (default)/bin/mygit2dx/iconv.dll" || (set FAIL_LINE=25& goto :ABORT)
cd /D "D:\Github\GP-Project-1\out\build\x64-Debug (default)" || (set FAIL_LINE=26& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: libmpg123.dll ..." || (set FAIL_LINE=27& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different D:/Github/GP-Project-1/cocos2d/external/win32-specific/MP3Decoder/prebuilt/libmpg123.dll "D:/Github/GP-Project-1/out/build/x64-Debug (default)/bin/mygit2dx/libmpg123.dll" || (set FAIL_LINE=28& goto :ABORT)
cd /D "D:\Github\GP-Project-1\out\build\x64-Debug (default)" || (set FAIL_LINE=29& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: libogg.dll ..." || (set FAIL_LINE=30& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different D:/Github/GP-Project-1/cocos2d/external/win32-specific/OggDecoder/prebuilt/libogg.dll "D:/Github/GP-Project-1/out/build/x64-Debug (default)/bin/mygit2dx/libogg.dll" || (set FAIL_LINE=31& goto :ABORT)
cd /D "D:\Github\GP-Project-1\out\build\x64-Debug (default)" || (set FAIL_LINE=32& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: libvorbis.dll ..." || (set FAIL_LINE=33& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different D:/Github/GP-Project-1/cocos2d/external/win32-specific/OggDecoder/prebuilt/libvorbis.dll "D:/Github/GP-Project-1/out/build/x64-Debug (default)/bin/mygit2dx/libvorbis.dll" || (set FAIL_LINE=34& goto :ABORT)
cd /D "D:\Github\GP-Project-1\out\build\x64-Debug (default)" || (set FAIL_LINE=35& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: libvorbisfile.dll ..." || (set FAIL_LINE=36& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different D:/Github/GP-Project-1/cocos2d/external/win32-specific/OggDecoder/prebuilt/libvorbisfile.dll "D:/Github/GP-Project-1/out/build/x64-Debug (default)/bin/mygit2dx/libvorbisfile.dll" || (set FAIL_LINE=37& goto :ABORT)
cd /D "D:\Github\GP-Project-1\out\build\x64-Debug (default)" || (set FAIL_LINE=38& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: OpenAL32.dll ..." || (set FAIL_LINE=39& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different D:/Github/GP-Project-1/cocos2d/external/win32-specific/OpenalSoft/prebuilt/OpenAL32.dll "D:/Github/GP-Project-1/out/build/x64-Debug (default)/bin/mygit2dx/OpenAL32.dll" || (set FAIL_LINE=40& goto :ABORT)
cd /D "D:\Github\GP-Project-1\out\build\x64-Debug (default)" || (set FAIL_LINE=41& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: zlib1.dll ..." || (set FAIL_LINE=42& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different D:/Github/GP-Project-1/cocos2d/external/zlib/../win32-specific/zlib/prebuilt/zlib1.dll "D:/Github/GP-Project-1/out/build/x64-Debug (default)/bin/mygit2dx/zlib1.dll" || (set FAIL_LINE=43& goto :ABORT)
cd /D "D:\Github\GP-Project-1\out\build\x64-Debug (default)" || (set FAIL_LINE=44& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: CloseNormal.png ..." || (set FAIL_LINE=45& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different D:/Github/GP-Project-1/Resources/CloseNormal.png "D:/Github/GP-Project-1/out/build/x64-Debug (default)/bin/mygit2dx/Resources/CloseNormal.png" || (set FAIL_LINE=46& goto :ABORT)
cd /D "D:\Github\GP-Project-1\out\build\x64-Debug (default)" || (set FAIL_LINE=47& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: CloseSelected.png ..." || (set FAIL_LINE=48& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different D:/Github/GP-Project-1/Resources/CloseSelected.png "D:/Github/GP-Project-1/out/build/x64-Debug (default)/bin/mygit2dx/Resources/CloseSelected.png" || (set FAIL_LINE=49& goto :ABORT)
cd /D "D:\Github\GP-Project-1\out\build\x64-Debug (default)" || (set FAIL_LINE=50& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: HelloWorld.png ..." || (set FAIL_LINE=51& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different D:/Github/GP-Project-1/Resources/HelloWorld.png "D:/Github/GP-Project-1/out/build/x64-Debug (default)/bin/mygit2dx/Resources/HelloWorld.png" || (set FAIL_LINE=52& goto :ABORT)
cd /D "D:\Github\GP-Project-1\out\build\x64-Debug (default)" || (set FAIL_LINE=53& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: fonts/Marker Felt.ttf ..." || (set FAIL_LINE=54& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different "D:/Github/GP-Project-1/Resources/fonts/Marker Felt.ttf" "D:/Github/GP-Project-1/out/build/x64-Debug (default)/bin/mygit2dx/Resources/fonts/Marker Felt.ttf" || (set FAIL_LINE=55& goto :ABORT)
cd /D "D:\Github\GP-Project-1\out\build\x64-Debug (default)" || (set FAIL_LINE=56& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: fonts/arial.ttf ..." || (set FAIL_LINE=57& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different D:/Github/GP-Project-1/Resources/fonts/arial.ttf "D:/Github/GP-Project-1/out/build/x64-Debug (default)/bin/mygit2dx/Resources/fonts/arial.ttf" || (set FAIL_LINE=58& goto :ABORT)
cd /D "D:\Github\GP-Project-1\out\build\x64-Debug (default)" || (set FAIL_LINE=59& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: res/.gitkeep ..." || (set FAIL_LINE=60& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different D:/Github/GP-Project-1/Resources/res/.gitkeep "D:/Github/GP-Project-1/out/build/x64-Debug (default)/bin/mygit2dx/Resources/res/.gitkeep" || (set FAIL_LINE=61& goto :ABORT)
goto :EOF

:ABORT
set ERROR_CODE=%ERRORLEVEL%
echo Batch file failed at line %FAIL_LINE% with errorcode %ERRORLEVEL%
exit /b %ERROR_CODE%