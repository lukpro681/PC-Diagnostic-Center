@echo off



echo Analizowanie tymczasowych plików aktualizacji...
echo NIE ZAMYKAJ TEGO OKNA!!!


DISM /Online /Cleanup-image /analyzecomponentstore
timeout /t 10 /nobreak