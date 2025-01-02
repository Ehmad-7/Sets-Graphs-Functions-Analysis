#include<iostream>
#include<vector>
#include<string>
using namespace std;

void printAdjacencymatrix(vector<vector<int>> matrix, int vertices)
{
    cout << endl << endl << "Adjacency Matrix" << endl;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void findPaths(vector<vector<int>>& matrix, int S, int E, int l, vector<int> path, vector<vector<int>>& allPaths)
{
    if (l == 0)
    {
        if (S == E)
        {
            allPaths.push_back(path);
        }
        return;
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[S][i] == 1)
        {
            path.push_back(i);
            findPaths(matrix, i, E, l - 1, path, allPaths);
            path.pop_back();
        }
    }
}

int main()
{
    while (true)
    {
        int a;
        cout << "Enter 0 to exit and 1 to continue: ";
        cin >> a;
        if (a == 0)
        {
            break;
        }
        else if (a == 1)
        {
            int vertices;
            while (true)
            {
                cout << "Enter number of vertices at least 4: ";
                cin >> vertices;
                if (vertices >= 4)
                    break;
                cout << "Invalid Input: Vertices should be 4 or more!" << endl;
            }

            string type;
            while (true)
            {
                cout << "Enter the type of the graph(directed OR undirected): ";
                cin >> type;
                if (type == "directed" || type == "undirected")
                    break;
                cout << "Invalid Input: Graph type must be directed or undirected!" << endl;
            }

            vector<vector<int>> adjacencyMatrix(vertices, vector<int>(vertices, 0));

            cout << endl << "Enter the Adjacency matrix row by row " << endl;
            for (int i = 0; i < vertices; i++)
            {
                while (true)
                {
                    cout << "Enter row no " << i + 1 << ": ";
                    bool valid = true;
                    for (int j = 0; j < vertices; j++)
                    {
                        cin >> adjacencyMatrix[i][j];
                        if (adjacencyMatrix[i][j] != 0 && adjacencyMatrix[i][j] != 1)
                        {
                            cout << "Invalid Input: Adjacency matrix is boolean type so values must be 0 or 1!" << endl;
                            valid = false;
                            break;
                        }
                        if (type == "undirected" && adjacencyMatrix[i][j] == 1)
                        {
                            adjacencyMatrix[j][i] = 1;
                        }
                    }
                    if (valid)
                        break;
                }
            }

            int S_vertex, E_vertex, P_length;

            while (true)
            {
                cout << "Enter the Starting Vertex From 0 to " << vertices - 1 << " : ";
                cin >> S_vertex;
                if (S_vertex >= 0 && S_vertex < vertices)
                    break;
                cout << "Invalid Input: Starting vertex must be within range!" << endl;
            }

            while (true)
            {
                cout << "Enter the Ending Vertex From 0 to " << vertices - 1 << " : ";
                cin >> E_vertex;
                if (E_vertex >= 0 && E_vertex < vertices)
                    break;
                cout << "Invalid Input: Ending vertex must be within range!" << endl;
            }

            while (true)
            {
                cout << "Enter the Desired path length greater than 0: ";
                cin >> P_length;
                if (P_length > 0)
                    break;
                cout << "Invalid Input: Path length must be greater than 0!" << endl;
            }

            printAdjacencymatrix(adjacencyMatrix, vertices);

            vector<int> path = { S_vertex };
            vector<vector<int>> allPaths;
            findPaths(adjacencyMatrix, S_vertex, E_vertex, P_length, path, allPaths);

            cout << "Number of paths (" << type << ", length " << P_length << ") from " << S_vertex << " to " << E_vertex << ": " << allPaths.size() << endl;
            cout << "Paths: ";
            for (int i = 0; i < allPaths.size(); i++)
            {
                for (int j = 0; j < allPaths[i].size(); j++)
                {
                    cout << allPaths[i][j] << " ";
                }
                cout << endl;
            }
        }
        else
        {
            cout << "Invalid input!" << endl;
        }
    }
    return 0;
}