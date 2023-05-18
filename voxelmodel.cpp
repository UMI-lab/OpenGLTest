#include "voxelmodel.h"

VoxelModel::VoxelModel(int grid_size)
{
    grid_size_ = grid_size;
    voxel_size_ = 1 / (GLfloat)grid_size_ / 2;
    srand(time(0));
    grid_size_x = grid_size_;
    grid_size_y = grid_size_;
    grid_size_z = grid_size_;

    voxel_size_x = voxel_size_;
    voxel_size_y = voxel_size_;
    voxel_size_z = voxel_size_;
    generateVoxels();
}

void VoxelModel::setGridSize(int grid_size)
{
    vertices.clear();
    color_array.clear();
    indices.clear();
    grid_size_ = grid_size;
    voxel_size_ = 1 / (GLfloat)grid_size_ / 2;
    grid_size_x = grid_size_;
    grid_size_y = grid_size_;
    grid_size_z = grid_size_;

    voxel_size_x = voxel_size_;
    voxel_size_y = voxel_size_;
    voxel_size_z = voxel_size_;
    generateVoxels();
}

GLfloat *VoxelModel::getVertices()
{
    return vertices.data();
}

GLfloat *VoxelModel::getColor()
{
    return color_array.data();
}

GLint *VoxelModel::getIndices()
{
    return indices.data();
}

int VoxelModel::getIndicesSize()
{
    return indices.size();
}

void VoxelModel::generateVoxels()
{
    // Итерируемся по трём измерениям
    for (int y = 0; y < grid_size_y; ++y) {
        for (int x = 0; x < grid_size_x; ++x) {
            for (int z = 0; z < grid_size_z; ++z) {
                // Добаляем немного рандома в шанс генерации вокселей
                GLfloat r_test = ((GLfloat) rand() / ((GLfloat)RAND_MAX));
                if (r_test > RANDOM_VOXEL_CHANCE) {

                    // Генерируем рандомный цвет вокселя
                    GLfloat r = ((GLfloat) rand() / ((GLfloat)RAND_MAX));
                    GLfloat g = ((GLfloat) rand() / ((GLfloat)RAND_MAX));
                    GLfloat b = ((GLfloat) rand() / ((GLfloat)RAND_MAX));

                    // Генерируем вершины для вокселя
                    // (центр вокселя находится в (x, y, z))
                    GLfloat vx = x * voxel_size_x;
                    GLfloat vy = y * voxel_size_y;
                    GLfloat vz = z * voxel_size_z;

                    // Генерируем вершины для каждой из 6 граней
                    // Первая грань
                    vertices.push_back(vx); vertices.push_back(vy); vertices.push_back(vz);
                    vertices.push_back(vx + voxel_size_x); vertices.push_back(vy); vertices.push_back(vz);
                    vertices.push_back(vx + voxel_size_x); vertices.push_back(vy + voxel_size_y); vertices.push_back(vz);
                    vertices.push_back(vx); vertices.push_back(vy + voxel_size_y); vertices.push_back(vz);

                    color_array.push_back(r); color_array.push_back(g); color_array.push_back(b);
                    color_array.push_back(r); color_array.push_back(g); color_array.push_back(b);
                    color_array.push_back(r); color_array.push_back(g); color_array.push_back(b);
                    color_array.push_back(r); color_array.push_back(g); color_array.push_back(b);

                    // Вторая грань
                    vertices.push_back(vx); vertices.push_back(vy); vertices.push_back(vz + voxel_size_z);
                    vertices.push_back(vx + voxel_size_x); vertices.push_back(vy); vertices.push_back(vz + voxel_size_z);
                    vertices.push_back(vx + voxel_size_x); vertices.push_back(vy + voxel_size_y); vertices.push_back(vz + voxel_size_z);
                    vertices.push_back(vx); vertices.push_back(vy + voxel_size_y); vertices.push_back(vz + voxel_size_z);

                    color_array.push_back(r); color_array.push_back(g); color_array.push_back(b);
                    color_array.push_back(r); color_array.push_back(g); color_array.push_back(b);
                    color_array.push_back(r); color_array.push_back(g); color_array.push_back(b);
                    color_array.push_back(r); color_array.push_back(g); color_array.push_back(b);

                    // Третья грань
                    vertices.push_back(vx); vertices.push_back(vy + voxel_size_y); vertices.push_back(vz);
                    vertices.push_back(vx + voxel_size_x); vertices.push_back(vy + voxel_size_y); vertices.push_back(vz);
                    vertices.push_back(vx + voxel_size_x); vertices.push_back(vy + voxel_size_y); vertices.push_back(vz + voxel_size_z);
                    vertices.push_back(vx); vertices.push_back(vy + voxel_size_y); vertices.push_back(vz + voxel_size_z);

                    color_array.push_back(r); color_array.push_back(g); color_array.push_back(b);
                    color_array.push_back(r); color_array.push_back(g); color_array.push_back(b);
                    color_array.push_back(r); color_array.push_back(g); color_array.push_back(b);
                    color_array.push_back(r); color_array.push_back(g); color_array.push_back(b);

                    // Четвертая грань
                    vertices.push_back(vx); vertices.push_back(vy); vertices.push_back(vz);
                    vertices.push_back(vx); vertices.push_back(vy); vertices.push_back(vz + voxel_size_z);
                    vertices.push_back(vx); vertices.push_back(vy + voxel_size_y); vertices.push_back(vz + voxel_size_z);
                    vertices.push_back(vx); vertices.push_back(vy + voxel_size_y); vertices.push_back(vz);

                    color_array.push_back(r); color_array.push_back(g); color_array.push_back(b);
                    color_array.push_back(r); color_array.push_back(g); color_array.push_back(b);
                    color_array.push_back(r); color_array.push_back(g); color_array.push_back(b);
                    color_array.push_back(r); color_array.push_back(g); color_array.push_back(b);

                    // Пятая грань
                    vertices.push_back(vx + voxel_size_x); vertices.push_back(vy); vertices.push_back(vz);
                    vertices.push_back(vx + voxel_size_x); vertices.push_back(vy); vertices.push_back(vz + voxel_size_z);
                    vertices.push_back(vx + voxel_size_x); vertices.push_back(vy + voxel_size_y); vertices.push_back(vz + voxel_size_z);
                    vertices.push_back(vx + voxel_size_x); vertices.push_back(vy + voxel_size_y); vertices.push_back(vz);

                    color_array.push_back(r); color_array.push_back(g); color_array.push_back(b);
                    color_array.push_back(r); color_array.push_back(g); color_array.push_back(b);
                    color_array.push_back(r); color_array.push_back(g); color_array.push_back(b);
                    color_array.push_back(r); color_array.push_back(g); color_array.push_back(b);

                    // Шестая грань
                    vertices.push_back(vx); vertices.push_back(vy); vertices.push_back(vz);
                    vertices.push_back(vx); vertices.push_back(vy); vertices.push_back(vz + voxel_size_z);
                    vertices.push_back(vx + voxel_size_x); vertices.push_back(vy); vertices.push_back(vz + voxel_size_z);
                    vertices.push_back(vx + voxel_size_x); vertices.push_back(vy); vertices.push_back(vz);

                    color_array.push_back(r); color_array.push_back(g); color_array.push_back(b);
                    color_array.push_back(r); color_array.push_back(g); color_array.push_back(b);
                    color_array.push_back(r); color_array.push_back(g); color_array.push_back(b);
                    color_array.push_back(r); color_array.push_back(g); color_array.push_back(b);

                    // Генерируем индексы для каждой из 6 граней
                    GLuint baseIndex = vertices.size() / 3 - 24;
                    for (int i = 0; i < 6; ++i)
                    {
                        indices.push_back(baseIndex + i * 4);
                        indices.push_back(baseIndex + i * 4 + 1);
                        indices.push_back(baseIndex + i * 4 + 2);

                        indices.push_back(baseIndex + i * 4);
                        indices.push_back(baseIndex + i * 4 + 2);
                        indices.push_back(baseIndex + i * 4 + 3);
                    }
                }
            }
        }
    }
}
