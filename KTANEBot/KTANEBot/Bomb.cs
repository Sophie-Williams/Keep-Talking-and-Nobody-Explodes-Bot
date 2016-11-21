using KTANEBot.Modules;
using System;

namespace KTANEBot
{
    public class Bomb
    {
        private enum Command
        {
            INVALID = -1,
            QUIT,
            INITIALIZE,
            BASIC_WIRES,
            BUTTON,
            KEYPAD,
            SIMON_SAYS,
            WHOS_ON_FIRST,
            MEMORY,
            MORSE_CODE,
            COMPLICATED_WIRES,
            WIRE_SEQUENCE,
            MAZE,
            PASSWORD,
            KNOB
        };

        public int strikes { get; private set; }
        public int batteries { get; private set; }
        public string serial { get; private set; }
        public string[] ports { get; private set; }
        public string[] litIndicators { get; private set; }
        public bool[] exisitingPorts { get; private set; }
        public bool lastSerialDigitOdd { get; private set; }
        public bool serialHasVowel { get; private set; }

        public Bomb() { }

        public void initializeBomb()
        {
            string bombProperty;

            while (true)
            {
                Console.Write("Please enter a bomb property followed by its values, separated by spaces: ");
                bombProperty = Console.ReadLine();

                string[] bombProperties = bombProperty.Split(' ');

                if (bombProperties[0] == "batteries")
                {
                    try
                    {
                        batteries = convertTextToInteger(bombProperties[1]);
                    }
                    catch (Exception ex)//todo)
                    {
                        Console.WriteLine("Invalid number of batteries entered. Please enter a valid number of batteries.");
                    }
                }
                else if (bombProperties[0] == "serial")
                {
                    serial = bombProperties[1];
                }
                else if (bombProperties[0] == "ports")
                {
                    bombProperties.CopyTo(ports, 1);
                }
                else if (bombProperties[0] == "indicators")
                {
                    bombProperties.CopyTo(litIndicators, 1);
                }
                else if (bombProperties[0] == "done")
                {
                    break;
                }
                else if (bombProperties[0] == "strike")
                {
                    ++strikes;
                }
                else
                {
                    Console.WriteLine("Invalid command.");
                }
            }

            if (ports != null)
            {
                setPorts(ports);
            }

            strikes = 0;
            isLastSerialDigitOdd(serial);
            doesSerialHaveVowel(serial);
        }

        private void isLastSerialDigitOdd(string serial)
        {
            //_ASSERT_EXPR(serial.length() == 6, "Invalid serial!");

            if ((serial[(serial.Length - 1)] % 2) == 0)
            {
                lastSerialDigitOdd = false;
                return;
            }

            lastSerialDigitOdd = true;
        }

        private void doesSerialHaveVowel(string serial)
        {
            foreach (char c in serial)
            {
                char tmp = char.ToLower(c);

                if ((tmp == 'a') ||
                    (tmp == 'e') ||
                    (tmp == 'i') ||
                    (tmp == 'o') ||
                    (tmp == 'u'))
                {
                    serialHasVowel = true;
                    return;
                }
            }

            serialHasVowel = false;
        }

        private void setPorts(string[] ports)
        {
            foreach (string port in ports)
            {
                if (port == "dvi")
                {
                    exisitingPorts[0] = true;
                }
                else if (port == "parallel")
                {
                    exisitingPorts[1] = true;
                }
                else if (port == "ps")
                {
                    exisitingPorts[2] = true;
                }
                else if (port == "rj")
                {
                    exisitingPorts[3] = true;
                }
                else if (port == "serial")
                {
                    exisitingPorts[4] = true;
                }
                else if (port == "stereo")
                {
                    exisitingPorts[5] = true;
                }
                else
                {
                    break;
                    //_ASSERT_EXPR(false, "Invalid port type!"); also if 0?
                }
            }
        }

        public void handleCommands()
        {
            string unparsedCommand = string.Empty;

            while (unparsedCommand != "quit")
            {
                Console.Write("Please enter a command: ");
                unparsedCommand = Console.ReadLine();

                Command parsedCommand = parseCommand(unparsedCommand);

                switch (parsedCommand)
                {
                    case Command.QUIT:
                        return;
                    case Command.INITIALIZE:
                        initializeBomb();
                        break;
                    case Command.BASIC_WIRES:
                        handleBasicWiresModule();
                        break;/*
                    case Commands.BUTTON:
                        handleButtonModule();
                        break;
                    case Commands.KEYPAD:
                        handleKeypadModule();
                        break;
                    case Commands.SIMON_SAYS:
                        handleSimonSaysModule();
                        break;
                    case Commands.WHOS_ON_FIRST:
                        handleWhosOnFirstModule();
                        break;
                    case Commands.MEMORY:
                        handleMemoryModule();
                        break;
                    case Commands.MORSE_CODE:
                        handleMorseCodeModule();
                        break;
                    case Commands.COMPLICATED_WIRE:
                        handleComplicatedWiresModule();
                        break;
                    case Commands.WIRE_SEQUENCE:
                        handleWireSequenceModule();
                        break;
                    case Commands.MAZE:
                        handleMazeModule();
                        break;
                    case Commands.PASSWORD:
                        handlePasswordModule();
                        break;
                    case Commands.KNOB:
                        handleKnobModule();
                        break;*/
                    default:
                        // ASSERT?
                        break;
                }
            }

            //_ASSERT_EXPR(false, "Unreachable code");
        }

        private Command parseCommand(string unparsedCommand)
        {
            if ((unparsedCommand == "quit") || (unparsedCommand == "exit"))
            {
                return Command.QUIT;
            }
            else if (unparsedCommand == "start")
            {
                return Command.INITIALIZE;
            }
            else if (unparsedCommand == "wires")
            {
                return Command.BASIC_WIRES;
            }
            else if (unparsedCommand == "button")
            {
                return Command.BUTTON;
            }
            else if (unparsedCommand == "keypad")
            {
                return Command.KEYPAD;
            }
            else if (unparsedCommand == "simon")
            {
                return Command.SIMON_SAYS;
            }
            else if (unparsedCommand == "whos")
            {
                return Command.WHOS_ON_FIRST;
            }
            else if (unparsedCommand == "memory")
            {
                return Command.MEMORY;
            }
            else if (unparsedCommand == "morse")
            {
                return Command.MORSE_CODE;
            }
            else if (unparsedCommand == "complex")
            {
                return Command.COMPLICATED_WIRES;
            }
            else if (unparsedCommand == "sequence")
            {
                return Command.WIRE_SEQUENCE;
            }
            else if (unparsedCommand == "maze")
            {
                return Command.MAZE;
            }
            else if (unparsedCommand == "password")
            {
                return Command.PASSWORD;
            }
            else if (unparsedCommand == "knob")
            {
                return Command.KNOB;
            }
            else
            {
                Console.WriteLine("Invalid command. Please enter a valid command.");
                return Command.INVALID;
            }
        }

        private int convertTextToInteger(string word)
        {
            if (word == "zero")
            {
                return 0;
            }
            else if (word == "one")
            {
                return 1;
            }
            else if (word == "two")
            {
                return 2;
            }
            else if (word == "three")
            {
                return 3;
            }
            else if (word == "four")
            {
                return 4;
            }
            else if (word == "five")
            {
                return 5;
            }
            else if (word == "six")
            {
                return 6;
            }
            else if (word == "seven")
            {
                return 7;
            }
            else if (word == "eight")
            {
                return 8;
            }
            else if (word == "nine")
            {
                return 9;
            }
            else
            {
                //_ASSERT_EXPR(false, "Unreachable code");
                return -1;
            }
        }

        private void handleBasicWiresModule()
        {
            string wireColors;
            Console.Write("Please enter the wire colors separated by spaces: ");
            wireColors = Console.ReadLine();

            string[] wires = (wireColors.Split(' '));

            BasicWiresModule basicWiresModule = new BasicWiresModule();
            Console.WriteLine("Cut: " + basicWiresModule.solveBasicWiresModule(wires));
        }
    }
}
