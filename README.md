# Message Queue for inter-thread communication
A message queue for inter-thread communication on Linux.

# Build and test
- Create a build directory and run cmake:

```
mkdir build
cd build
cmake ..
```

- Build the project:

```
make
```

- Run the test executable:

```
./testapp
```

- Shared library
  
  After successfull compilation, a shared library `libmessagequeue.so` is available in the `build` directory.
