#include <iostream>
#include <regex>

int main()
{
	std::string str = R"("ARTHUR: Three questions may cross in safety. "
"ROBIN: What if you get a question wrong? "
"ARTHUR: Then you are cast into the Gorge of Eternal Peril. "
"ROBIN: Oh, I won't go. "
"GALAHAD: Who's going to answer the questions? "
"ARTHUR: Sir Robin! "
"ROBIN: Yes? "
"ARTHUR: Brave Sir Robin, you go. "
"ROBIN: Hey! I've got a great idea. Why doesn't Lancelot go? "
"LANCELOT: Yes. Let me go, my liege. I will take him single-handed. I shall make a feint to the north-east that s-- "
"ARTHUR: No, no. No. Hang on! Hang on! Hang on! Just answer the five questions-- "
"GALAHAD: Three questions. "
"ARTHUR: Three questions as best you can, and we shall watch... and pray. "
"LANCELOT: I understand, my liege. "
"ARTHUR: Good luck, brave Sir Lancelot. God be with you. "
"BRIDGEKEEPER: Stop! Who would cross the Bridge of Death must answer me these questions three, ere the other side he see. "
"LANCELOT: Ask me the questions, bridgekeeper. I am not afraid. "
"BRIDGEKEEPER: What... is your name? "
"LANCELOT: My name is 'Sir Lancelot of Camelot'. "
"BRIDGEKEEPER: What... is your quest? "
"LANCELOT: To seek the Holy Grail. "
"BRIDGEKEEPER: What... is your favorite color? "
"LANCELOT: Blue. "
"BRIDGEKEEPER: Right. Off you go. "
"LANCELOT: Oh, thank you. Thank you very much. "
"ROBIN: That's easy! "
"BRIDGEKEEPER: Stop! Who approacheth the Bridge of Death must answer me these questions three, ere the other side he see. "
"ROBIN: Ask me the questions, bridgekeeper. I'm not afraid. "
"BRIDGEKEEPER: What... is your name? "
"ROBIN: 'Sir Robin of Camelot'. "
"BRIDGEKEEPER: What... is your quest? "
"ROBIN: To seek the Holy Grail. "
"BRIDGEKEEPER: What... is the capital of Assyria? "
"[pause] "
"ROBIN: I don't know that! Auuuuuuuugh! "
"BRIDGEKEEPER: Stop! What... is your name? "
"GALAHAD: 'Sir Galahad of Camelot'. "
"BRIDGEKEEPER: What... is your quest? "
"GALAHAD: I seek the Grail. "
"BRIDGEKEEPER: What... is your favorite color? "
"GALAHAD: Blue. No, yel-- auuuuuuuugh! "
"BRIDGEKEEPER: Hee hee heh. Stop! What... is your name? "
"ARTHUR: It is 'Arthur', King of the Britons. "
"BRIDGEKEEPER: What... is your quest? "
"ARTHUR: To seek the Holy Grail. "
"BRIDGEKEEPER: What... is the air-speed velocity of an unladen swallow? "
"ARTHUR: What do you mean? An African or European swallow? "
"BRIDGEKEEPER: Huh? I-- I don't know that. Auuuuuuuugh! alek ")";
	std::smatch matches;
	//nie wiem jak rozumiec wyraz wiec zrobilem 2 interpretacje
	//1 - wyraz sklada sie tylko z liter i cyfr i np. air-speed to 2 wyrazy - air i speed
	//2 - wyraz sklada sie rowniez z niebialych znakow i np. air-speed to jeden wyraz
	std::regex pattern(R"([^[:alnum:]]([a-df-zA-DF-Z0-9][[:alnum:]]*a[[:alnum:]]*)|(a[[:alnum:]]*)[^[:alnum:]])");
	//std::regex pattern(R"(\s([a-df-zA-DF-Z0-9]\S*a\S*)|(a\S*)\s)");
	while (std::regex_search(str, matches, pattern))
	{
		if (matches.str(1) == "")
			std::cout << matches.str(2) << std::endl;
		else
			std::cout << matches.str(1) << std::endl;
		str = matches.suffix().str();
	}
}