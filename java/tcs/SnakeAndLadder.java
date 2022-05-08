package tcs;

import java.util.HashSet;

public class SnakeAndLadder {
    // create a enum for the cell types
    enum CellType {
        EMPTY, LADDER, SNAKE
    }

    static class Cell {
        int cellNumber;
        CellType cellType;
        int jumpTo;

        Cell(int cellNumber) {
            this.cellNumber = cellNumber;
            cellType = CellType.EMPTY;
            jumpTo = 0;
        }

        Cell(int cellNumber, CellType cellType, int jumpTo) {
            this.cellNumber = cellNumber;
            this.cellType = cellType;
            this.jumpTo = jumpTo;
        }
    }

    public static HashSet<Cell> generateBoard(int boardSize) {
        HashSet<Cell> board = new HashSet<>();
        for (int i = 1; i <= boardSize; i++) {
            if (i == 1 || i == 4 || i == 9 || i == 28 || i == 21 || i == 36 || i == 51 || i == 71 || i == 80) {
                board.add(new Cell(i, CellType.LADDER, i + 20));
            } else if (i == 16 || i == 49 || i == 47 || i == 56 || i == 64) {
                board.add(new Cell(i, CellType.SNAKE, i - 6));
            } else {
                board.add(new Cell(i));
            }
        }
        return board;
    }

    public static int rollDice() {
        return (int) (Math.random() * 6) + 1;
    }

    public static void main(String args[]) {
        HashSet<Cell> board = generateBoard(100);
        int player1 = 0;
        int player2 = 0;
        
    }
}
