#ifndef VOXELMODEL_H
#define VOXELMODEL_H
#include <vector>
#include <QGLWidget>

const float RANDOM_VOXEL_CHANCE = 0.7;

class VoxelModel
{
public:
    VoxelModel(int grid_size);
    void setGridSize(int grid_size);
    GLfloat * getVertices();
    GLfloat * getColor();
    GLint * getIndices();
    int getIndicesSize();

private:
    void generateVoxels();

    int grid_size_;
    int grid_size_x;
    int grid_size_y;
    int grid_size_z;
    GLfloat voxel_size_;
    GLfloat voxel_size_x;
    GLfloat voxel_size_y;
    GLfloat voxel_size_z;

    std::vector<GLfloat> vertices; // Вектор вершин
    std::vector<GLint> indices; // Вектор индексов
    std::vector<GLfloat> color_array; // Вектор цветов
};

#endif // VOXELMODEL_H
