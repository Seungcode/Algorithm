#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    std::vector<std::vector<int>> board(n + 1, std::vector<int>(n + 1, 0));

    const int roof = 1, column = 2;

    auto roofCheck = [&](int x, int y) {

        if (0 < y && (board[x][y - 1] & column))
        {
            return true;
        }

        if (0 < y && n > x && (board[x + 1][y - 1] & column))
        {
            return true;
        }

        if (0 < x && (board[x - 1][y] & roof) && n > x && (board[x + 1][y] & roof))
        {
            return true;
        }

        return false;
    };

    auto columnCheck = [&](int x, int y) {

        if (0 == y)
        {
            return true;
        }

        if (0 < y && (board[x][y - 1] & column))
        {
            return true;
        }

        if (board[x][y] & roof)
        {
            return true;
        }

        if (0 < x && (board[x - 1][y] & roof))
        {
            return true;
        }

        return false;
    };

    auto allCheck = [&]() {
        for (int x = 0; x <= n; ++x)
        {
            for (int y = 0; y <= n; ++y)
            {
                if (board[x][y] & roof)
                {
                    if (!roofCheck(x, y))
                    {
                        return false;
                    }
                }
                if (board[x][y] & column)
                {
                    if (!columnCheck(x, y))
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    };

    for (const auto& ele : build_frame)
    {
        int x = ele[0];
        int y = ele[1];
        int part = ele[2] ? roof : column;
        int install = ele[3];

        if (install)
        {
            board[x][y] |= part;
            if (!allCheck())
            {
                board[x][y] &= ~(part);
            }
        }
        else
        {
            board[x][y] &= ~(part);
            if (!allCheck())
            {
                board[x][y] |= part;
            }
        }
    }

    for (int x = 0; x <= n; ++x)
    {
        for (int y = 0; y <= n; ++y)
        {
            if (board[x][y] & roof)
            {
                answer.push_back({x, y, 1});
            }
            if (board[x][y] & column)
            {
                answer.push_back({x, y, 0});
            }
        }
    }

    std::sort(answer.begin(), answer.end(), [](auto& lhs, auto& rhs) {
        if (lhs[0] == rhs[0])
        {
            if (lhs[1] == rhs[1])
            {
                return lhs[2] < rhs[2];
            }
            return lhs[1] < rhs[1];
        }
        return lhs[0] < rhs[0];
    });

    return answer;
}