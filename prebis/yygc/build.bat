flex -osrt.c -I srt.l 
if errorlevel 1 goto :EOF
cl  srt.c
