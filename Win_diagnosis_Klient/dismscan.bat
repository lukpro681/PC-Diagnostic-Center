@echo off



echo Skanowanie magazynu systemu plikow...
echo NIE ZAMYKAJ TEGO OKNA!!!


DISM /Online /Cleanup-Image /scanhealth
timeout /t 10 /nobreak