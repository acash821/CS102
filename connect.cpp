#include <iostream>
#include <string>
using namespace std;


void gameboard(string point[6][6])
{
    cout << "___________" << endl;
    cout << "|" << point[0][0] << "|" << point[0][1] << "|" << point[0][2] << "|" << point[0][3] <<
        "|" << point[0][4] << "|" << point[0][5] << "|" << endl;
    cout << "|" << point[1][0] << "|" << point[1][1] << "|" << point[1][2] << "|" << point[1][3] <<
        "|" << point[1][4] << "|" << point[1][5] << "|" << endl;
    cout << "|" << point[2][0] << "|" << point[2][1] << "|" << point[2][2] << "|" << point[2][3] <<
        "|" << point[2][4] << "|" << point[2][5] << "|" << endl;
    cout << "|" << point[3][0] << "|" << point[3][1] << "|" << point[3][2] << "|" << point[3][3] <<
        "|" << point[3][4] << "|" << point[3][5] << "|" << endl;
    cout << "|" << point[4][0] << "|" << point[4][1] << "|" << point[4][2] << "|" << point[4][3] <<
        "|" << point[4][4] << "|" << point[4][5] << "|" << endl;
    cout << "|" << point[5][0] << "|" << point[5][1] << "|" << point[5][2] << "|" << point[5][3] <<
        "|" << point[5][4] << "|" << point[5][5] << "|" << endl;
}

string win (string array[6][6], string marker)
{
    int y_coor = 0;
    while (y_coor < 6)
    {
        int x_coor = 0;
        int count = 0;
        while (x_coor < 3)
        {
            int duplicate_x = x_coor;
            for (int i = 0; i < 4; i++)
            {
                if (array[y_coor][duplicate_x] == marker)
                {
                    count++;
                }
                else
                {
                    count = 0;
                }
                duplicate_x++;
            }
            if (count == 4)
            {
                return "win";
            }
            x_coor++;
        }
        y_coor++;
    }

    int x_coor = 0;
    while (x_coor < 6)
    {
        int y_coor = 0;
        int count = 0;
        while (y_coor < 3)
        {
            int duplicate_y = y_coor;
            for (int i = 0; i < 4; i++)
            {
                if (array[duplicate_y][x_coor] == marker)
                {
                    count++;
                }
                else
                {
                    count = 0;
                }
                duplicate_y++;
            }
            if (count == 4)
            {
                return "win";
            }
            y_coor++;
        }
        x_coor++;
    }

    int x_coord = 0;
    int y_coord = 0;
    int count = 0;

    while (x_coord < 3)
    {
        y_coord = 0;
        while (y_coord < 3)
        {
            if (array[x_coord][y_coord] == marker && array[x_coord + 1][y_coord + 1] == marker
                && array[x_coord + 2][y_coord + 2] == marker && array[x_coord + 3][y_coord + 3] == marker)
            {
                return "win";
            }
            y_coord++;
        }
        x_coord++;
    }

    x_coord = 5; 
count = 0;

    while (x_coord > 2)
    {
        y_coord = 0;
        while (y_coord < 3)
        {
            if (array[x_coord][y_coord] == marker && array[x_coord - 1][y_coord + 1] == marker
                && array[x_coord - 2][y_coord + 2] == marker && array[x_coord - 3][y_coord + 3] == marker)
            {
                return "win";
            }
            y_coord++;
        }
        x_coord--;
    }

    return "progress";
}

int main()
{
    int player = 1;
    string marker = " ";
    int row = 0;
    int column = 0;
    string outcome = "progress";
    string point[6][6];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            point[i][j] = "_";
        }
    }

    gameboard(point);

    while (outcome == "progress")
    {
        if (player % 2 == 0)
        {
            player = 2;
        }
        else
            player = 1;

        if (player == 1)
            marker = "X";
        else
            marker = "O";
        cout << "enter a row number from 1-6: ";
        cin >> row;
        row = row - 1;
        cout << "enter a column number from 1-6: ";
        cin >> column;
        column = column - 1;
        if (point[row][column] == "_")
        {
            if (player == 1)
            {
                point[row][column] = marker;
                gameboard(point);
                outcome = win(point, marker);
                if (outcome == "win")
                    cout << "Player 1 wins" << endl;
                if (outcome == "draw")
                    cout << "draw" << endl;
                player++;
            }
            else
            {
                point[row][column] = marker;
                gameboard(point);
                outcome = win(point, marker);
                if (outcome == "win")
                    cout << "Player 1 wins" << endl;
                if (outcome == "draw")
                    cout << "draw" << endl;
                player++;
            }
        }
        else
        {
            cout << "input out of range" << endl;
        }
    }
}
