@echo off



echo Czyszczenie tymczasowych plików aktualizacji...
echo NIE ZAMYKAJ TEGO OKNA!!!


DISM /Online /Cleanup-image /startcomponentcleanup
timeout /t 10 /nobreak