@echo off
cls
echo Compiling Parliament Election System...

:: Compile all .c files into one executable
gcc main_menu.c officer_login.c officer_dashboard.c candidate_requests.c candidate_gateway.c candidate_login.c candidate_register.c candidate_dashboard.c voter_gateway.c voter_login.c voter_register.c voter_dashboard.c voter_requests.c show_results.c generate_results.c -o election.exe

:: Check if compilation succeeded
if exist election.exe (
    echo ✅ Compilation successful!
    echo Running the program...
    echo ------------------------------
    election.exe
) else (
    echo ❌ Compilation failed. Please check your code.
)

pause