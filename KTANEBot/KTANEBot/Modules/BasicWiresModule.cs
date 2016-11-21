namespace KTANEBot.Modules
{
    public class BasicWiresModule
    {
        public string solveBasicWiresModule(string[] wires)
        {
            int numberOfWires = wires.Length;

            //_ASSERT((numberOfWires >= 3) && (numberOfWires <= 6));

            switch (numberOfWires)
            {
                case 3:
                    if (countWiresOfColor(wires, "red") == 0)
                    {
                        return "second";
                    }

                    if (wires[(numberOfWires - 1)] == "white")
                    {
                        return "last";
                    }

                    if (countWiresOfColor(wires, "blue") > 1)
                    {
                        return "last blue";
                    }

                    return "last";
                case 4:
                    if ((countWiresOfColor(wires, "red") > 1) && Program._bomb.lastSerialDigitOdd)
                    {
                        return "last red";
                    }

                    if ((wires[(numberOfWires - 1)] == "yellow") && (countWiresOfColor(wires, "red") == 0))
                    {
                        return "first";
                    }

                    if (countWiresOfColor(wires, "blue") == 1)
                    {
                        return "first";
                    }

                    if (countWiresOfColor(wires, "yellow") > 1)
                    {
                        return "last";
                    }

                    return "second";
                case 5:
                    if ((wires[(numberOfWires - 1)] == "black") && Program._bomb.lastSerialDigitOdd)
                    {
                        return "fourth";
                    }

                    if ((countWiresOfColor(wires, "red") == 1) && countWiresOfColor(wires, "yellow") > 1)
                    {
                        return "first";
                    }

                    if (countWiresOfColor(wires, "black") == 0)
                    {
                        return "second";
                    }

                    return "first";
                case 6:
                    if ((countWiresOfColor(wires, "yellow") == 0) && Program._bomb.lastSerialDigitOdd)
                    {
                        return "third";
                    }

                    if ((countWiresOfColor(wires, "yellow") == 1) && (countWiresOfColor(wires, "white") > 1))
                    {
                        return "fourth";
                    }

                    if (countWiresOfColor(wires, "red") == 0)
                    {
                        return "last";
                    }

                    return "fourth";
            }

            //_ASSERT(false);

            return "error";
        }

        private int countWiresOfColor(string[] wires, string color)
        {
            int count = 0;

            for (int i = 0; i < wires.Length; ++i)
            {
                if (wires[i] == color)
                {
                    ++count;
                }
            }

            return count;
        }
    }
}
