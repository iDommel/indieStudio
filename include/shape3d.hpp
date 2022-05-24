#ifndef SHAPE3DH
    #define SHAPE3DH

    struct Vector3;
    struct Color;

    /**struct Shape3D;
     * @brief Shape3D object
     */ 
    class shape3D {
        public:
            /**
             * @brief Construct a new shape3D object
             */
            shape3D();
            /**
             * @brief Destroy shape3D object
             */
            ~shape3D();

            /**
             * @brief Draw sphere 
             * @param centerPos position of the center of the sphere
             * @param radius raduis of the sphere
             * @param color Color of the sphere
             */
            void DrawSphere(Vector3 centerPos, float radius, Color color);
            /**
             * @brief Draw cube 
             * @param position position of the center of the sphere
             * @param size size {x, y, z} of the cube
             * @param color Color of the cube
             */
            void DrawCube(Vector3 position, Vector3 size, Color color);
            /**
             * @brief Draw grid 
             * @param slices size of the grid 
             * @param spacing size of one slice 
             */
            void DrawGrid(int slices, float spacing);

    };

#endif /* !MODELH */