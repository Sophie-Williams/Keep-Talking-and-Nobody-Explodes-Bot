using System;
using System.Runtime.InteropServices;
using System.Speech.Recognition;
using System.Speech.Synthesis;

namespace BombSpeechHandler
{
    class Program
    {
        //[DllImport("BombDefusalBot.dll")]

        static void Main(string[] args)
        {
            Choices basic = new Choices("start", "stop", "battery", "serial", "port", "indicator", "strike");
            Choices colors = new Choices("white", "red", "yellow", "blue", "purple", "black");
            Choices numbers = new Choices("zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine");
            Choices ordinals = new Choices("first", "second", "third", "fourth", "fifth", "sixth", "last");
            Choices ports = new Choices("dvi", "parallel", "ps", "rj", "serial", "stereo");
            Choices modules = new Choices("wires", "button", "keypad", "simon", "who's", "memory", "morse", "complex", "sequence", "maze", "password", "knob");
            Choices button = new Choices("abort", "detonate", "hold");
            Choices complex = new Choices("light", "star");
            Choices maze = new Choices("square", "triangle");
            Choices morse = new Choices("short", "long");
            Choices whos = new Choices
            (
                  "blank", "c", "cee", "display", "done", "first", "hold on", "hold", "lead", "led", "leed", "left", "like", "middle", "next",
                  "no", "nothing", "null", "okay", "press", "read", "ready", "red", "reed", "right", "says", "see", "sure", "their", "there",
                  "they are", "they're", "u", "uh huh", "uh uh", "uhhh", "ur", "wait", "what", "what?", "yes", "you are", "you", "you're", "your"
            );
            Choices symbols = new Choices
            (
                "oh", "tee", "lambda", "lightning", "kitty", "hotel", "backwardsee", "euro", "oh", "backwardsee", "quebec", "star", "hotel", "question",
                "copyright", "butt", "quebec", "doublepsi", "are", "lambda", "star", "sigma", "paragraph", "bee", "kitty", "doublepsi", "question",
                "smiley", "psi", "smiley", "bee", "see", "paragraph", "caterpillar", "star", "sigma", "euro", "tracks", "diphthong", "psi", "en", "omega"
            );

            GrammarBuilder basicGrammar = new GrammarBuilder();
            basicGrammar.Append(basic);
            GrammarBuilder colorsGrammar = new GrammarBuilder();
            colorsGrammar.Append(colors);
            GrammarBuilder numbersGrammar = new GrammarBuilder();
            numbersGrammar.Append(numbers);
            GrammarBuilder ordinalsGrammar = new GrammarBuilder();
            ordinalsGrammar.Append(ordinals);
            GrammarBuilder portsGrammar = new GrammarBuilder();
            portsGrammar.Append(ports);
            GrammarBuilder modulesGrammar = new GrammarBuilder();
            modulesGrammar.Append(modules);
            GrammarBuilder buttonGrammar = new GrammarBuilder();
            buttonGrammar.Append(button);
            GrammarBuilder complexGrammar = new GrammarBuilder();
            complexGrammar.Append(complex);
            GrammarBuilder mazeGrammar = new GrammarBuilder();
            mazeGrammar.Append(maze);
            GrammarBuilder morseGrammar = new GrammarBuilder();
            morseGrammar.Append(morse);
            GrammarBuilder whosGrammar = new GrammarBuilder();
            whosGrammar.Append(whos);
            GrammarBuilder symbolsGrammar = new GrammarBuilder();
            symbolsGrammar.Append(symbols);

            Grammar bombGrammar = new Grammar(basicGrammar);
            SpeechRecognizer speechRecognizer = new SpeechRecognizer();

            speechRecognizer.LoadGrammarAsync(bombGrammar);
            speechRecognizer.SpeechRecognized += new EventHandler<SpeechRecognizedEventArgs>(sre_SpeechRecognized);

            while (true)
            {

            }
        }

        static void sre_SpeechRecognized(object sender, SpeechRecognizedEventArgs e)
        {
            Console.WriteLine("Speech recognized: " + e.Result.Text);
        }
    }
}
