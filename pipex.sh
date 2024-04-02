#!/bin/bash

GREEN="\033[32m"
CLEAR="\033[0m"
DELAY=0.05
DURATION=2


start_time=$(date +%s)

while true; do
    current_time=$(date +%s)
    elapsed_time=$((current_time - start_time))
    if [ $elapsed_time -ge $DURATION ]; then
        break
    fi
    clear
    for ((i=0; i<3; i++)); do
        for ((j=0; j<59; j++)); do
            if [ $((RANDOM % 2)) -eq 0 ]; then
                echo -en "${GREEN}█${CLEAR}"
            else
                echo -en " "
            fi
        done
        echo
    done
    echo -e "${GREEN}░▒▓███████▓▒░░▒▓█▓▒░▒▓███████▓▒░░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░${CLEAR}"
    echo -e "${GREEN}░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░${CLEAR}"
    echo -e "${GREEN}░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░${CLEAR}"
    echo -e "${GREEN}░▒▓███████▓▒░░▒▓█▓▒░▒▓███████▓▒░░▒▓██████▓▒░  ░▒▓██████▓▒░ ${CLEAR}"
    echo -e "${GREEN}░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░${CLEAR}"
    echo -e "${GREEN}░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░${CLEAR}"
    echo -e "${GREEN}░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░      ░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░${CLEAR}"
    for ((i=0; i<3; i++)); do
        for ((j=0; j<59; j++)); do
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
