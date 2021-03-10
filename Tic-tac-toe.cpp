#include <iostream>
#include <map>

using namespace std;

char grid[12] = {'0', '1', '2', '/', '3', '4', '5', '/', '6', '7', '8', '/'}; //game grid
int cnt = 1, turn = 0;
char Sign, player_one, player_two;
string C;
map<string, int> can; //Check The Cell If Visited Or No

// to reset game grid if the game Ended with draw and the players want playing again
void reset()
{
  grid[0] = '0', grid[1] = '1', grid[2] = '2', grid[3] = '/', grid[4] = '3', grid[5] = '4', grid[6] = '5',
  grid[7] = '/', grid[8] = '6', grid[9] = '7', grid[10] = '8', grid[11] = '/';
}

// Check if there are Winner or No
bool Wins(char grid[12])
{
  //horizontal cells
  if (grid[0] == grid[1] && grid[1] == grid[2])
    return true;
  else if (grid[4] == grid[5] && grid[5] == grid[6])
    return true;
  else if (grid[8] == grid[9] && grid[9] == grid[10])
    return true;
  //vertical cells
  else if (grid[0] == grid[4] && grid[4] == grid[8])
    return true;
  else if (grid[1] == grid[5] && grid[5] == grid[9])
    return true;
  else if (grid[2] == grid[6] && grid[6] == grid[10])
    return true;
  //diagonal cells
  else if (grid[0] == grid[5] && grid[5] == grid[10])
    return true;
  else if (grid[2] == grid[5] && grid[5] == grid[8])
    return true;
  else
    return false;
}

// representation of grid
void Matrix()
{
  cout << "     |     |     " << endl;
  cout << "  " << grid[0] << "  |  " << grid[1] << "  |  " << grid[2] << endl;
  cout << "_____|_____|_____" << endl;
  cout << "     |     |     " << endl;
  cout << "  " << grid[4] << "  |  " << grid[5] << "  |  " << grid[6] << endl;
  cout << "_____|_____|_____" << endl;
  cout << "     |     |     " << endl;
  cout << "  " << grid[8] << "  |  " << grid[9] << "  |  " << grid[10] << endl;
  cout << "     |     |     " << endl;
}
int main()
{

again:;
againI:;
  cout << "player one : X or O\n";
  cin >> Sign;
  if (Sign == 'X' || Sign == 'O')
  {
    ;
  }
  else
  {
    cout << "please Enter X or O, Try again ^_^\n";
    goto againI;
  }
  player_one = Sign;
  player_two = (player_one == 'X' ? 'O' : 'X');
  //cout << "Player One: " << player_one << ", Player Two " << player_two << ".\n\n";
  can.clear();
  bool invalid = false; // if the input out of the boundary or the cell already visited
  while (true)
  {

    if (can.size() == 9)
    {
      system("clear");
      cout << "Draw, nice try ^_^\n";
      Matrix();
      cout << "if You want play again click 1, else click any button\n";
      int f;
      cin >> f;
      if (f == 1)
      {
        reset();
        goto again;
      }
      else
      {
        return 0;
      }
    }
    system("clear");
    if (invalid)
    {
      cout << "invalid game please play again!!\n\n";
      invalid = false;
    }
    cout << "Player One: " << player_one << ", Player Two " << player_two << ".\n\n";
    Matrix();
    cout << "Select position\n";
    cin >> C;
    int a = stoi(C); // stoi to Convert String to integer
    if (a > 8)
    {
      invalid = true;
    }
    else if (can[C])
    {
      invalid = true;
    }
    else
    {
      if (cnt & 1)
      {
        can[C]++;
        for (int i = 0; i < 12; i++)
          if (grid[i] == C[0])
          {
            grid[i] = player_one;
            break;
          }
      }
      else
      {
        can[C]++;
        for (int i = 0; i < 12; i++)
          if (grid[i] == C[0])
          {
            grid[i] = player_two;
            break;
          }
      }

      if (Wins(grid))
      {
        if (cnt & 1)
        {
          system("clear");
          cout << "congratulations ^_^\n";
          Matrix();
          cout << player_one << " Win :D" << endl;
          return 0;
        }
        else
        {
          system("clear");
          cout << "congratulations ^_^\n";
          Matrix();
          cout << player_two << " Win :D" << endl;
          return 0;
        }
      }
      cnt++;
    }
  }
  return 0;
}
