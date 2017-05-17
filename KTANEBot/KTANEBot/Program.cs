using System;
using System.Threading;

namespace KTANEBot
{
    public class Program
    {
        public static Bomb _bomb { get; private set; }
        public static SpeechRecognition _speechRecognitionParser { get; private set; }
        public static SpeechSynthesis _speechSynthesizer { get; private set; }

        static void Main(string[] args)
        {
            _bomb = new Bomb();
            _speechRecognitionParser = new SpeechRecognition();
            _speechSynthesizer = new SpeechSynthesis();

            //Thread speechRecognitionThread = new Thread(new ThreadStart(<something>));
            Thread speechSynthesizerThread = new Thread(new ThreadStart(_speechSynthesizer.Speak));
            //Thread bombThread (mainThread?) = new Thread(new ThreadStart(<something>));

            speechSynthesizerThread.Start();
            speechSynthesizerThread.Join();
            /*

            _bomb.handleCommands();

            /* TODO: Move this into the bomb handler itself, or have a main thread that does this work */
            /*Console.WriteLine("Defusal ended.");
            bool playAgain = false;
            do
            {
                Console.WriteLine("Would you like to defuse another bomb? Y/N: ");
                string yesOrNo = Console.ReadLine();

                if (yesOrNo.ToLower()[0] == 'y')
                {
                    _bomb.handleCommands();
                    playAgain = true;
                }
                else
                {
                    playAgain = false;
                }
            } while (playAgain);*/
        }
    }
}
