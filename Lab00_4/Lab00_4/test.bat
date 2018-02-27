REM ������ ��������� ��� ����������

set PROGRAM="%~1"

IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ����� ���������� ����������
test.exe notANumber
IF NOT ERRORLEVEL 1 GOTO err

REM ������ ��������� � ������ ������� � �������� ������ �� ����������
test.exe ""
IF NOT ERRORLEVEL 1 GOTO err

REM ������ ��������� � ����� �������� ���������� (� ��������� ���������)
test.exe -123 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt -123.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ����� ��������� �����������
test.exe 15 2 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 15+2=17.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ����� ��������� �����������
test.exe 15 2 -8 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 15+2+-8=9.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)
EXIT

:err
ECHO Program testing failed :-(
EXIT