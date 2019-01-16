# Travelling Salesman Problem
### Using an Evolutionary Algorithm (EA)

## Synopsis
This project have as purpose study the basic concepts of an Evolutionary Algorithm and use them to solve the Travelling Salesman Problem.

## Software Requirements
* [CMake](https://cmake.org/) (minimum version required 2.8)
* [Gnuplot](http://www.gnuplot.info/)

## Build

Go to the project folder _TravellingSalesman_ and execute:
```
cd build
cmake ..
make
```
## Run
Go inside the dir _TravellingSalesman/bin_ and execute:  
```./TravellingSalesman <cities_filename> <population_size> <mutation_prob> <number_of_generations>```


Cities file format:
```Name Lat Lon``` Show an example in the `./mockdata/` dir
> Remember, north is the positive value for the Lat, and East is the positive value for the Lon, In that case the Mexico city with coordinates `Mexico 19.4326° N 99.1332° W` should be added in the file like `Mexico 19.4326 -99.1332`

Population Size: Number of individuals in each generation

Mutation prob: Probability of mutation in children of a generation, float number between 0 - 1

Number of generation: max amount of generated generations




## Tests

`make test`

## Authors
* **Luis Nezij Aguilar Islas** - *Initial work* - [luisaguilar2910](https://github.com/luisaguilar2910) - luisaguilar2910@gmail.com

## License

This project is licensed under the MIT License.
