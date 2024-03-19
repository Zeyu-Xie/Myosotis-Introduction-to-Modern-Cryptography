#!/bin/zsh

# Config Variables
name="gcc_11"

result=$(docker images -q --filter "reference=$name" | head -n 1)
# No Image Found
if [ "$result" = "" ]; then
    echo -e "\e[1;31mDocker Image not Found\e[0m"
    echo -n "- Do you want to build the image now? (Y/N) "
    read option
    if [ "$option" = "Y" ] || [ "$option" = "y" ]; then
        docker build -t $name $(dirname $0)
    else
        echo "You have canceled building the image."
    fi
# Image Exists    
else
    echo -e "\e[1;32mImage Exists\e[0m"
    docker_time=$(docker inspect --format='{{.Created}}' $name | head -n 1)
    echo "Your image was created at $docker_time."
    echo -e "\e[0;34m1. Run Image"
    echo -e "2. Remove Image"
    echo -e "3. Exit\e[0m"
    echo -e -n "- Please choose your option (1-3): "
    read option
    if [ "$option" = "1" ]; then
        docker run -i -v $(dirname $0):/app -t $result
    elif [ "$option" = "2" ]; then
        docker rmi -f $result
        echo "Image $result has been removed."
    elif [ "$option" = "3" ]; then
        echo "You have canceled image running."
    else
        echo "ERROR: Illegal Option. Quit."
    fi
fi