using System.Speech.Synthesis;

namespace KTANEBot
{
    public class SpeechSynthesis
    {
        private readonly SpeechSynthesizer speechSynthesizer;

        public SpeechSynthesis()
        {
            speechSynthesizer = new SpeechSynthesizer();
            speechSynthesizer.SetOutputToDefaultAudioDevice();
        }

        public void Speak()
        {
            string textToSpeak = "Hello, world!";
            speechSynthesizer.Speak(textToSpeak);
        }
    }
}
