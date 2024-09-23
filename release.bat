@echo off

set /p version=< "src\VERSION"

rmdir /s /q "release\latest"
mkdir "release\latest"
xcopy /v /e "seyhan\lib\" "release\latest\lib\"
cmake -DCMAKE_BUILD_TYPE:STRING=Release -Wno-deprecated --no-warn-unused-cli -S "." -B "release\latest\build" -G Ninja
cmake --build "release\latest\build" --config release --target cey
copy /v "release\latest\build\cey.exe" "release\latest\cey.exe"
rmdir /s /q "release\latest\build"

cd "release\latest"
del "..\cey-%version%.zip"
7z a -tzip "..\cey-%version%.zip" "*"
cd "..\.."
