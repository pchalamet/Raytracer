# About
Old raytracer implemented in C circa 1997 during my studies.
Support scene description (parsed using flex and bison). Support CSG and boolean operations.

Build it using `make`.

# License
Do what you want with that code !


# Samples

![Rendering](https://github.com/pchalamet/Raytracer/blob/master/RENDERING/IMG.jpg?raw=true)


```
camera { position <0, 0, -64>
	 width 128
	 height 80 }

%%

lamp { position <10, -10, -5>
       intensity 10 }

%%

sphere { scale <55, 55, 55>
 	 translation <-20, -15, 80>

	 diffuse [0.6, 0.1, 0.1]
	 specular [0, 0, 0]
	 reflect [1, 1, 1]
	 aspect 2.0 }

plane { translation <0, 30, 0>

	diffuse [0.5,0.3,0]
	specular [0.5, 0.2, 0.2]
	aspect 4.0
	tile 50 }
```

