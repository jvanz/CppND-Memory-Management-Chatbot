#ifndef CHATLOGIC_H_
#define CHATLOGIC_H_

#include <vector>
#include <string>
#include <memory>
#include "chatgui.h"
#include "graphnode.h"

// forward declarations
class ChatBot;

class ChatLogic
{
private:
    // data handles (owned)
    std::vector<std::unique_ptr<GraphNode>> _nodes;

    // data handles (not owned)
    GraphNode *_currentNode;
    ChatBot *_chatBot;
    ChatBotPanelDialog *_panelDialog;

    // proprietary type definitions
    typedef std::vector<std::pair<std::string, std::string>> tokenlist;

    // proprietary functions
    template <typename T>
    void AddAllTokensToElement(std::string tokenID, tokenlist &tokens, T &element);

public:
    // constructor / destructor
    ChatLogic() {};
    ChatLogic(ChatLogic&& source);
    ChatLogic& operator=(ChatLogic&& source);
    // Chatlogic cannot be copied because of the vector of unique_ptr to the nodes
    ChatLogic(const ChatLogic& source) = delete;
    ChatLogic& operator=(const ChatLogic& source) = delete;

    // getter / setter
    void SetPanelDialogHandle(ChatBotPanelDialog *panelDialog);
    void SetChatBot(ChatBot *chatbot) { _chatBot = chatbot; }

    // proprietary functions
    void LoadAnswerGraphFromFile(std::string filename);
    void SendMessageToChatbot(std::string message);
    void SendMessageToUser(std::string message);
    wxBitmap *GetImageFromChatbot();
};

#endif /* CHATLOGIC_H_ */
