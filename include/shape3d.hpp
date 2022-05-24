
struct Vector3;
struct Color;

class shape3D {
    public:
        shape3D();
        ~shape3D();

        void DrawSphere(Vector3 centerPos, float radius, Color color);
        void DrawCube(Vector3 position, Vector3 size, Color color);
        void DrawGrid(int slices, float spacing);

};