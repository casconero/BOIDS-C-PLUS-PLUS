Boids c++ Project
==============

Boids c++ Project_ is a research initiative by 100cells (Costanzo D'Angelis, Stefano Cieri).

Introduction
------------

Boids c++ Project_ is an open source project aimed to write a boids simulator able to export the simulation in a maya cache readable form.
The project uses the Maya nCache for nParticles library. You can find the c code here: https://github.com/casconero/Maya-Cache-DLL-Project.
This implementation is merely resulting out of observations (and deductions) of .mc binary files and Python scripts provided by Autodesk.

####Maya Caches, nCaches and nParticles
The Maya Cache file format (.mc) is used in Maya for a variety of caching purposes; nCaches are a sub-class of Maya Caches, which store simulation data for nucleus objects or fluid effects; nParticles 
are a specific kind of nucleus objects.
Presently, the library only deals with the file structure of nCaches for nParticles.

Most likely, this will be the first step of a wider research, aimed to generalize the format description (so that it might include every kind of Maya Cache).

This project uses a third part kdtree library. This library is developed by John Tsiombikas
The KDTree folder should contain files from John Tsiombikas' library.
For more informations about the kdtree library implementation we suggest you to ask to John Tsiombikas.
All information about the library can be found at http://code.google.com/p/kdtree/ .

Documentation
--------------
The official Maya nCache project's page can be found at: [http://blog.100cells.com/maya-cache-dll-project](http://blog.100cells.com/maya-cache-dll-project).
More detailed instructions can be found at: [http://blog.100cells.com/maya-cache-dll-project/maya-cache-dll-instructions/] (http://blog.100cells.com/maya-cache-dll-project/maya-cache-dll-instructions/).