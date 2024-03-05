#include <raylib.h>
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

const int Width = 800;
const int Height = 800;
const int blockSize = 5;
const int cols = Height / blockSize;
const int row = Width / blockSize;

void DrawSand(int row, int col)
{
    // Calculate hue based on column position
    float hue = static_cast<float>(col + row) / static_cast<float>(cols) * 360.0f;
    float saturation = 1.0f;
    Color color = ColorFromHSV(hue, saturation, 1.0f);

    DrawRectangle(col * blockSize, row * blockSize, blockSize, blockSize, color);
}

void mouse(int (*array)[row])
{
    Vector2 position = GetMousePosition();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            Rectangle rec = {static_cast<float>(i * blockSize),
                             static_cast<float>(j * blockSize),
                             static_cast<float>(blockSize),
                             static_cast<float>(blockSize)};
            if (CheckCollisionPointRec(position, rec))
            {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                {
                    array[j][i] = 1;
                }
            }
        }
    }
}

int main()
{
    InitWindow(Width, Height, "Falling Sand");

    int blocks[Height / blockSize][Width / blockSize];

    // Make all the value to 0
    for (int i = 0; i < Height / blockSize; i++)
    {
        for (int j = 0; j < Width / blockSize; j++)
        {
            blocks[i][j] = 0;
        }
    }

    int fallSpeed = 0;

    SetTargetFPS(80);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw sand if the block is value is 1
        for (int i = 0; i < Height / blockSize; i++)
        {
            for (int j = 0; j < Width / blockSize; j++)
            {
                if (blocks[i][j] == 1)
                {
                    DrawSand(i, j);
                }
            }
        }

        // Update values for the next frame
        int nextBlocks[Height / blockSize][Width / blockSize];

        // Make all the value to 0
        for (int i = 0; i < Height / blockSize; i++)
        {
            for (int j = 0; j < Width / blockSize; j++)
            {
                nextBlocks[i][j] = 0;
            }
        }

        mouse(nextBlocks);
        for (int i = 0; i < Height / blockSize; i++)
        {
            for (int j = 0; j < Width / blockSize; j++)
            {
                if (blocks[i][j] == 1)
                {
                    if (blocks[i + 1][j] == 0 && i < cols - 1)
                    {
                        nextBlocks[i + 1][j] = 1;
                    }
                    else if (blocks[i + 1][j - 1] == 0 && j > 0 && i < cols - 1 && blocks[i + 1][j] == 1)
                    {
                        nextBlocks[i + 1][j - 1] = 1;
                    }
                    else if (blocks[i + 1][j + 1] == 0 && j + 1 < cols && i < cols - 1 && blocks[i + 1][j] == 1)
                    {
                        nextBlocks[i + 1][j + 1] = 1;
                    }
                    else
                    {
                        nextBlocks[i][j] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < Height / blockSize; i++)
        {
            for (int j = 0; j < Width / blockSize; j++)
            {
                blocks[i][j] = nextBlocks[i][j];
            }
        }
        EndDrawing();
    }

    CloseWindow();
}
