#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <cstring>

int main() {
    int pipefds[2];
    char buffer[6]; // 5 for data + 1 for '\0'

    // Create pipe
    if (pipe(pipefds) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    const char* pin = "4128"; // No need to manually add \0

    std::cout << "Writing PIN to pipe\n";
    write(pipefds[1], pin, strlen(pin) + 1); // write 5 bytes (4 digits + '\0')
    std::cout << "Done\n\n";

    std::cout << "Reading PIN from pipe\n";
    ssize_t bytesRead = read(pipefds[0], buffer, sizeof(buffer) - 1); // read 5 bytes max
    buffer[bytesRead] = '\0'; // null terminate
    std::cout << "Done\n\n";

    std::cout << "PIN from pipe: " << buffer << std::endl;

    return EXIT_SUCCESS;
}
