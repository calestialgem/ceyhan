@echo off

for /f "tokens=2 delims==" %%a in ('wmic OS Get localdatetime /value') do set "dt=%%a"
set "YY=%dt:~2,2%" & set "YYYY=%dt:~0,4%" & set "MM=%dt:~4,2%" & set "DD=%dt:~6,2%"
set "HH=%dt:~8,2%" & set "II=%dt:~10,2%" & set "SS=%dt:~12,2%"

set version=%YYYY%%MM%%DD%%HH%%II%%SS%

rmdir /s /q "rel\latest"
mkdir "rel\latest"

cmake -DCMAKE_BUILD_TYPE:STRING=Release -Wno-deprecated --no-warn-unused-cli -S "." -B "rel\latest\build" -G Ninja
cmake --build "rel\latest\build" --config release --target cey
copy /v "rel\latest\build\cey.exe" "rel\latest\cey.exe"
rmdir /s /q "rel\latest\build"

cd "rel\latest"
del "..\cey-%version%.zip"
7z a -tzip "..\cey-%version%.zip" "*"
cd "..\.."
