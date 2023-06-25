@echo off


echo Konfiguracja programu CheckDisk...
echo y | chkdsk c: /f
echo Narzedzie CheckDisk zostanie uruchomione w czasie ponownego uruchomiania komputera
timeout /t 10 /nobreak


