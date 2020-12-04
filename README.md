# Build and Run the Code

- To build the code, we use the programming language C++ version 11
    - The code was written in Visual Studio 2017/2019 and Visual Studio Code
    
- To compile the code, we use the g++ compiler. 

- To get binary executable program, we use command line at Linux terminal which “g++ -std=c++11 *.h *.cpp”
    - Compile all header files which: bst.h, command_borrow.h, command_history.h, command_return.h, customers_collection.h, media.h, media_factory.h, media_movie_classic.h, media_movie_drama.h, store_manager.h, command.h, command_factory.h, command_inventory.h, customer.h, hashtable.h, media_collection.h, media_movie.h, media_movie_comedy.h, media_movie_factory.h
        
    - Compile all implementation files which: command.cpp, command_factory.cpp, command_inventory.cpp, customer.cpp, main.cpp, media_collection.cpp, media_movie.cpp          media_movie_comedy.cpp, media_movie_factory.cpp, command_borrow.cpp, command_history.cpp, command_return.cpp, customers_collection.cpp, media.cpp, media_factory.cpp, media_movie_classic.cpp, media_movie_drama.cpp, store_manager.cpp
    
- To check memory leak, we use the command line at the Linux terminal which “valgrind ./a.out”
    - The memory leak was carefully detected and manageable. There is no memory leak in this project
    
# How the Application Process

- Precondition: To sucessfully run the program, some .txt files need to be included as corrected form
    - data4customers.txt, this file contain all customer information
    - data4movies.txt, this files contain all movies information
    - data4commands.txt, this file contain all command to be executed
 
- Processing:
    - 1: A Store is instantiated in main
    - 2: Build the customers by reading each customer from "data4customers.txt"
        - Store all customer in Customer Collection
    - 3: Build the movies by reading each movies from "data4movies.txt"
        - Store all movies in Media Collection
    - 4: Process commands by reading each command from "data4commands.txt"
        - Get commands then access Customer and Media Collection to process commands.
