@echo off
echo Rozpoczynanie skanowania chronionych plikow systemowych...
echo NIE ZAMYKAJ TEGO OKNA!!!


sfc /scannow

timeout /t 10 /nobreak