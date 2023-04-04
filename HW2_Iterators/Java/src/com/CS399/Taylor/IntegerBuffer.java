package com.CS399.Taylor;

// IntegerBuffer.java
public class IntegerBuffer {
    int data[];
    int dataLength = 0;

    private class IntegerBufferIterator extends GoFIterator {
        int cursor;

        @Override
        void first() {
            cursor = 0;
        }
        @Override
        void next() {
            if(!isDone()) cursor++;
        }
        @Override
        boolean isDone() {
            return cursor >= dataLength;
        }
        @Override
        int currentItem() {
            return (cursor >= 0 && cursor < dataLength) ? 0 : data[cursor];
        }
    }

    public IntegerBuffer(int capacity) {
        data = new int[capacity];
    }

    private GoFIterator createIterator() {
        return new IntegerBufferIterator();
    }

    public boolean add(int value) {
        if (dataLength < data.length) {
            data[dataLength] = value;
            ++dataLength;
            return true;
        } else
            return false;
    }

    public int add(int values[]) {
        int count = 0;
        for (int i = 0; i < values.length; ++i)
            if (add(values[i]))
                ++count;
        return count;
    }

    public static void main(String args[]) {
        int values[] =
                {23, 12, -6, 14, 0, 37, -26, 5, 11, -4, 16, 12, 8, -3, 6, -2};
        IntegerBuffer ibuf = new IntegerBuffer(32);;
        ibuf.add(values);
        ibuf.add(values);
        System.out.println("Java");

        // this section tests the iterator
        int column = 0;
        GoFIterator iter = ibuf.createIterator();
        for (iter.first(); !iter.isDone(); iter.next()) {
            if (column >= 10) {
                System.out.println();
                column = 1;
            } else
                ++column;
            System.out.format("%5d", iter.currentItem());
        }
        System.out.println();
        // end if iterator test

    }
}
