if cmake --build build; then
	./build/Boids
else
	echo "Build Failed"
	exit 1
fi
