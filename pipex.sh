#!/bin/bash

GREEN="\033[32m"
CLEAR="\033[0m"
DELAY=0.05
DURATION=2

# Start time
start_time=$(date +%s)

while true; do
    # Get current time
    current_time=$(date +%s)
    
    # Calculate elapsed time
    elapsed_time=$((current_time - start_time))
    
    # Exit loop after 5 seconds
    if [ $elapsed_time -ge $DURATION ]; then
        break
    fi

    clear

    # Print Matrix-like pattern before "pipex"
    for ((i=0; i<3; i++)); do
        for ((j=0; j<60; j++)); do
            if [ $((RANDOM % 2)) -eq 0 ]; then
                echo -en "${GREEN}█${CLEAR}"
            else
                echo -en " "
            fi
        done
        echo
    done

    # Print "pipex" with Matrix-like pattern in the middle
    echo -e "${GREEN}░▒▓███████▓▒░░▒▓█▓▒░▒▓███████▓▒░░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░${CLEAR}"
    echo -e "${GREEN}░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░${CLEAR}"
    echo -e "${GREEN}░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░${CLEAR}"
    echo -e "${GREEN}░▒▓███████▓▒░░▒▓█▓▒░▒▓███████▓▒░░▒▓██████▓▒░  ░▒▓██████▓▒░ ${CLEAR}"
    echo -e "${GREEN}░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░${CLEAR}"
    echo -e "${GREEN}░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░${CLEAR}"
    echo -e "${GREEN}░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░      ░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░${CLEAR}"

    # Print Matrix-like pattern after "pipex"
    for ((i=0; i<3; i++)); do
        for ((j=0; j<60; j++)); do
            if [ $((RANDOM % 2)) -eq 0 ]; then
                echo -en "${GREEN}█${CLEAR}"
            else
                echo -en " "
            fi
        done
        echo
    done

    sleep $DELAY
done
