#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    int mood_choice, sub_choice;
    char feedback[256];
    float rating = 0.0;

    // 1. Welcome Message
    printf("\n");
    printf("    🤖  Welcome to the Mood Responder System! 😊\n");
    printf("\n\n");

    // 2. Mood Menu
    printf("How are you feeling today?\n");
    printf("1. 😄 Happy\n");
    printf("2. 😔 Sad\n");
    printf("3. 😖 Tired/Stressed\n");
    printf("4. 😡 Angry\n");
    printf("Please enter your mood choice (1-4): ");

    // Input validation for main menu
    if (scanf("%d", &mood_choice) != 1) {
        printf("\nInvalid input! Please enter a number. Exiting program.\n");
        return 1;
    }

    // Clear input buffer after scanf
    while (getchar() != '\n'); 

    printf("\n--- You chose mood number '%d'. ---\n\n", mood_choice);

    // 3. Main Switch: Sub-Menu and Reactions based on Mood
    switch (mood_choice) {
        case 1: // HAPPY Mood Logic
            printf("😄 Why are you Happy?\n");
            printf("1. Did you achieve or win something?\n");
            printf("2. Has someone impressed you?\n");
            printf("3. Did you get your favorite food/dress?\n");
            printf("4. Another reason?\n");
            printf("Please choose a reason (1-4): ");
            scanf("%d", &sub_choice);
            while (getchar() != '\n'); // Clear buffer

            switch (sub_choice) {
                case 1:
                    printf("\n✨ Fantastic! Celebrate your success! You are truly inspiring.\n");
                    break;
                case 2:
                    printf("\n💖 That's wonderful! Being surrounded by good people is always a joy.\n");
                    break;
                case 3:
                    printf("\n😋 Enjoy your favorite thing! It's great to find happiness in small pleasures.\n");
                    break;
                case 4:
                    printf("\n😊 Whatever the reason, we are happy that you are happy! Keep this joy going.\n");
                    break;
                default:
                    printf("\nInvalid option. Message: Today is your day! Make the most of it.\n");
            }
            // 4. Suggestion
            printf("\n*Suggestion:* Keep it up! Share your happiness with a friend or family member.\n");
            rating = 8.5; 
            break;

        case 2: // SAD Mood Logic
            printf("😔 Why are you Sad?\n");
            printf("1. Do you miss your family or friends?\n");
            printf("2. Did you lose something important?\n");
            printf("3. Are you feeling unwell (sick)?\n");
            printf("4. Another reason?\n");
            printf("Please choose a reason (1-4): ");
            scanf("%d", &sub_choice);
            while (getchar() != '\n'); // Clear buffer

            switch (sub_choice) {
                case 1:
                    printf("\n🫂 Memories are a blessing. Embrace them and try to call your loved ones. They are your strength.\n");
                    break;
                case 2:
                    printf("\n💔 We understand how hard this is. But remember, you are stronger than your losses. This feeling will pass.\n");
                    break;
                case 3:
                    printf("\n🌡 Take care of yourself. Rest, eat well, and stay hydrated. Health comes first.\n");
                    break;
                case 4:
                    printf("\n🌧 Sadness is a temporary cloud. You will get through this. Believe in yourself.\n");
                    break;
                default:
                    printf("\nInvalid option. Message: This time too shall pass. Have faith in yourself.\n");
            }
            // 4. Suggestion
            printf("\n*Suggestion:* Motivate yourself. Go for a short 5-minute walk or listen to some soothing music.\n");
            rating = 7.0; 
            break;

        case 3: // TIRED/STRESSED Mood Logic
            printf("😖 Why are you Tired/Stressed?\n");
            printf("1. Do you have a big workload?\n");
            printf("2. Are you having trouble managing tasks/time?\n");
            printf("3. Are you dealing with feeling of depression or overwhelm?\n");
            printf("4. Another reason?\n");
            printf("Please choose a reason (1-4): ");
            scanf("%d", &sub_choice);
            while (getchar() != '\n'); // Clear buffer

            switch (sub_choice) {
                case 1:
                    printf("\n📚 Work can be overwhelming. Focus on one task at a time and take small, frequent breaks.\n");
                    break;
                case 2:
                    printf("\n🧠 Start by making a small 'To-Do' list. Give each task a time limit. You can manage this!\n");
                    break;
                case 3:
                    printf("\n😔 It is crucial that you seek help. Talk to a trusted person or a professional. You are not alone.\n");
                    break;
                case 4:
                    printf("\n🧘 Take a deep breath. Calm your mind. This stress is temporary.\n");
                    break;
                default:
                    printf("\nInvalid option. Message: Pause for a moment and breathe. Cool your mind down.\n");
            }
            // 4. Suggestion
            printf("\n*Suggestion:* Cool up. Take a 10-minute power nap or watch an entertaining video.\n");
            rating = 6.5; 
            break;

        case 4: // ANGRY Mood Logic
            printf("😡 Why are you Angry?\n");
            printf("1. Did you have a fight with someone?\n");
            printf("2. Did someone cause you to lose something dear to you?\n");
            printf("3. Did a colleague or boss underestimate you?\n"); 
            printf("4. Another reason?\n");
            printf("Please choose a reason (1-4): ");
            scanf("%d", &sub_choice);
            while (getchar() != '\n'); // Clear buffer

            switch (sub_choice) {
                case 1:
                    printf("\n🔥 A fight only increases tension. Take a deep breath and try to understand the situation calmly.\n");
                    break;
                case 2:
                    printf("\n💔 We understand your frustration. But anger does not solve the problem. Think peacefully about the next step.\n");
                    break;
                case 3:
                    printf("\n😤 Don't let anyone disturb your peace. Focus on your work and prove your worth. Their words cannot define you.\n");
                    break;
                case 4:
                    printf("\n💣 Express your anger safely. Punch a pillow or shout (when alone) to let it out.\n");
                    break;
                default:
                    printf("\nInvalid option. Message: Anger is like holding a hot coal. Let it cool.\n");
            }
            printf("\n*Suggestion:* Calm Down. Count to 10, drink water, and walk away from the situation for a few minutes.\n");
            rating = 6.0; 
            break;

        default:
            printf("\n❌ Please select a valid option between 1 and 4.\n");
            return 1; 
    }

    // 5. Feedback and Rating
    printf("\n--- What did you do to improve your mood? ---\n");
    printf("Did you follow our suggestion? (Enter positive/negative keywords): ");
    
    // Use fgets for multi-word input
    fgets(feedback, sizeof(feedback), stdin);
    // Remove newline character added by fgets
    feedback[strcspn(feedback, "\n")] = 0; 

    // Adjust rating based on feedback
    // Check for positive keywords (case-insensitive check for simplicity)
    if (strstr(feedback, "yes") || strstr(feedback, "did") || strstr(feedback, "positive") || strstr(feedback, "well") || strstr(feedback, "better")) {
        rating += 1.5; // Increase rating for positive response
        if (rating > 10.0) rating = 10.0; // Cap at 10.0
        printf("\n✅ Feedback Result: Excellent! We are glad you are feeling better.\n");
    } else {
        // Negative/Neutral response
        printf("\n💡 Feedback Result: Okay, there's always room for improvement. Try again next time.\n");
    }

    // Display final rating
    printf("⭐ Your mood response rating is: %.1f/10\n", rating);

    // Final Conclusion Message
    printf("\n**\n");
    printf("    🎉  Well Done! You are perfect! Have a great day! 🎈\n");
    printf("\n");

    return 0;
}