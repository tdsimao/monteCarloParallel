monteCarloParallel
==================

This program run a multi-thread rotine that estimates the value of Pi using 
the Monte Carlo method.

The mainly contribution is the use of lpthread to implement several  threads 
running at the same time so we can take advantage of the multicore processors
	

to compile
==========
gcc -lpthread src/monteCarlo.c -o bin/rotinaSinal

to run
======
./bin/rotinaSinal <numberOfThreads> <numberOfSamples>
