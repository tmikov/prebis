@echo off
bison -v -k -n test.y
if errorlevel 1 goto :EOF
cl -Zi test.tab.c
