# Requirments

In Ubuntu Linux, the list of requirements are all installed using `requirements.sh`. Run the script.

# Build
In the root of this repository, you can issue the following command to compile the project
```
cmake -S . -B build -DSAF_ENABLE_SOFA_READER_MODULE=1 -DSAF_PERFORMANCE_LIB=SAF_USE_OPEN_BLAS_AND_LAPACKE
```