@echo off
cls

echo Compilando o projeto...

:: Comando de compilacao
gcc main.c ^
PreCadastro_FilaEstaticaCircular/implement.c ^
FilaAtendimento_FilaDinamica/implement.c ^
-o app.exe -Wall

:: Verifica se o executavel foi criado
if exist app.exe (
    echo.
    echo Compilacao concluida com sucesso!
    echo Iniciando o aplicativo...
    start app.exe
) else (
    echo.
    echo ----------------------------------------------------
    echo ERRO: A compilacao falhou.
    echo O arquivo "app.exe" nao foi encontrado.
    echo Verifique as mensagens de erro do compilador acima.
    echo ----------------------------------------------------
)

echo.
pause