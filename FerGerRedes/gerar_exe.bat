@echo off
REM Gera os executaveis exigidos na entrega (fonte + binarios no zip)
REM Pre-requisito: pip install pyinstaller

echo Gerando servidor.exe ...
pyinstaller --onefile --console --name servidor servidor.py

echo Gerando cliente.exe ...
pyinstaller --onefile --console --name cliente cliente.py

echo.
echo Pronto! Os executaveis estao na pasta dist\
pause
