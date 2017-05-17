using System;
using System.Speech.Recognition;

namespace KTANEBot
{
    public class SpeechRecognition
    {
        private readonly Choices basic = new Choices("start", "stop", "battery", "serial", "port", "indicator", "strike");
        private readonly Choices modules = new Choices("wires", "button", "keypad", "simon", "who's", "memory", "morse", "complex", "sequence", "maze", "password", "knob");
        private readonly Choices ports = new Choices("dvi", "parallel", "ps", "rj", "serial", "stereo");
        private readonly Choices colors = new Choices("white", "red", "yellow", "blue", "purple", "black");
        private readonly Choices numbers = new Choices("zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine");
        private readonly Choices ordinals = new Choices("first", "second", "third", "fourth", "fifth", "sixth", "last");
        private readonly Choices button = new Choices("abort", "detonate", "hold");
        private readonly Choices complexWires = new Choices("light", "star");
        private readonly Choices maze = new Choices("square", "triangle");
        private readonly Choices morseCode = new Choices("short", "long");
        private readonly Choices whosOnFirst = new Choices
        (
              "blank", "c", "cee", "display", "done", "first", "hold on", "hold", "lead", "led", "leed", "left", "like", "middle", "next",
              "no", "nothing", "null", "okay", "press", "read", "ready", "red", "reed", "right", "says", "see", "sure", "their", "there",
              "they are", "they're", "u", "uh huh", "uh uh", "uhhh", "ur", "wait", "what", "what?", "yes", "you are", "you", "you're", "your"
        );
        private readonly Choices symbols = new Choices
        (
            "oh", "tee", "lambda", "lightning", "kitty", "hotel", "backwardsee", "euro", "oh", "backwardsee", "quebec", "star", "hotel", "question",
            "copyright", "butt", "quebec", "doublepsi", "are", "lambda", "star", "sigma", "paragraph", "bee", "kitty", "doublepsi", "question",
            "smiley", "psi", "smiley", "bee", "see", "paragraph", "caterpillar", "star", "sigma", "euro", "tracks", "diphthong", "psi", "en", "omega"
        );

        private GrammarBuilder basicGrammar;
        private GrammarBuilder modulesGrammar;
        private GrammarBuilder portsGrammar;
        private GrammarBuilder colorsGrammar;
        private GrammarBuilder numbersGrammar;
        private GrammarBuilder ordinalsGrammar;
        private GrammarBuilder buttonGrammar;
        private GrammarBuilder complexWiresGrammar;
        private GrammarBuilder mazeGrammar;
        private GrammarBuilder morseCodeGrammar;
        private GrammarBuilder whosOnFirstGrammar;
        private GrammarBuilder symbolsGrammar;

        private Grammar bombGrammar;

        private SpeechRecognizer speechRecognizer;

        public SpeechRecognition()
        {
            basicGrammar = new GrammarBuilder();
            modulesGrammar = new GrammarBuilder();
            portsGrammar = new GrammarBuilder();
            colorsGrammar = new GrammarBuilder();
            numbersGrammar = new GrammarBuilder();
            ordinalsGrammar = new GrammarBuilder();
            buttonGrammar = new GrammarBuilder();
            complexWiresGrammar = new GrammarBuilder();
            mazeGrammar = new GrammarBuilder();
            morseCodeGrammar = new GrammarBuilder();
            whosOnFirstGrammar = new GrammarBuilder();
            symbolsGrammar = new GrammarBuilder();

            InitializeGrammars();

            Grammar bombGrammar = new Grammar(basicGrammar);

            speechRecognizer = new SpeechRecognizer();
            speechRecognizer.LoadGrammarAsync(bombGrammar);
            speechRecognizer.SpeechRecognized += new EventHandler<SpeechRecognizedEventArgs>(sre_SpeechRecognized);
        }

        private void InitializeGrammars()
        {
            basicGrammar.Append(basic);
            colorsGrammar.Append(colors);
            numbersGrammar.Append(numbers);
            ordinalsGrammar.Append(ordinals);
            portsGrammar.Append(ports);
            modulesGrammar.Append(modules);
            buttonGrammar.Append(button);
            complexWiresGrammar.Append(complexWires);
            mazeGrammar.Append(maze);
            morseCodeGrammar.Append(morseCode);
            whosOnFirstGrammar.Append(whosOnFirst);
            symbolsGrammar.Append(symbols);
        }

        public void sre_SpeechRecognized(object sender, SpeechRecognizedEventArgs e)
        {
            Console.WriteLine("Speech recognized: " + e.Result.Text);
        }
    }
}
