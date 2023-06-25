@echo off


echo Naprawa magazynu systemu plikow...
echo NIE ZAMYKAJ TEGO OKNA!!!


DISM /Online /Cleanup-Image /restorehealth
timeout /t 10 /nobreak