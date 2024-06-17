from openai import OpenAI
client = OpenAI()


def have_conversation(prompt):
    messages = [{
        'role': 'system',
        'content': prompt
    }]

    while True:
        user_input = input('User: ')
        if not user_input:
            break

        messages.append({
            'role': 'user',
            'content': user_input
        })

        response = client.chat.completions.create(
        model="gpt-4o",
            messages=messages
        )
        bot_message = response.choices[0].message
        messages.append(bot_message)

        print(bot_message.content)


def main():
    prompt = """
    The user provides journal entries. Suggest tags for the entry.
    """
    have_conversation(prompt)
    

if __name__ == '__main__':
    main()
