# Quiz Component Documentation

The Quiz component is a comprehensive, interactive quiz system that supports both multiple choice (single answer) and multiple answer questions.

## Features

- ✅ Multiple choice questions (single answer)
- ✅ Multiple answer questions
- ✅ Automatic scoring system
- ✅ Detailed explanations for each question
- ✅ Visual feedback (green for correct, red for incorrect)
- ✅ Progress tracking
- ✅ Mobile responsive design
- ✅ Supports rich content (markdown, HTML, etc.)

## Usage

### Basic Quiz

```astro
---
import Quiz from '../components/Quiz.astro';

const questions = [
  {
    id: 'q1',
    type: 'single',
    question: 'What is the capital of France?',
    options: [
      { id: 'a', text: 'London' },
      { id: 'b', text: 'Berlin' },
      { id: 'c', text: 'Paris' },
      { id: 'd', text: 'Madrid' }
    ],
    correctAnswers: ['c'],
    explanation: 'Paris is the capital and largest city of France.'
  },
  {
    id: 'q2',
    type: 'multiple',
    question: 'Which of the following are programming languages?',
    options: [
      { id: 'a', text: 'JavaScript' },
      { id: 'b', text: 'HTML' },
      { id: 'c', text: 'Python' },
      { id: 'd', text: 'CSS' }
    ],
    correctAnswers: ['a', 'c'],
    explanation: 'JavaScript and Python are programming languages, while HTML and CSS are markup languages.'
  }
];
---

<Quiz title="Geography Quiz" questions={questions} />
```

### Quiz with Rich Content

The component supports markdown and HTML in questions and options:

```astro
---
import Quiz from '../components/Quiz.astro';

const questions = [
  {
    id: 'q1',
    type: 'single',
    question: 'What is 2 + 2?',
    options: [
      { 
        id: 'a', 
        text: '3' 
      },
      { 
        id: 'b', 
        text: '4' 
      },
      { 
        id: 'c', 
        text: '5' 
      },
      { 
        id: 'd', 
        text: '6' 
      }
    ],
    correctAnswers: ['b'],
    explanation: 'The sum of 2 and 2 equals 4.'
  }
];
---

<Quiz title="Math Quiz" questions={questions} />
```

## Props

| Prop | Type | Required | Default | Description |
|------|------|----------|---------|-------------|
| `questions` | `Array<Question>` | Yes | - | Array of question objects |
| `title` | `string` | No | - | Title to display above the quiz |

## Question Object Structure

```typescript
interface Question {
  id: string;                    // Unique identifier for the question
  type: 'single' | 'multiple';   // Question type
  question: string | any;         // Question text or rich content
  options: Array<{
    id: string;                  // Unique identifier for the option
    text: string | any;          // Option text or rich content
  }>;
  correctAnswers: string[];     // Array of correct answer IDs
  explanation?: string | any;   // Optional explanation shown after submission
}
```

## Features Breakdown

### 1. Multiple Choice (Single Answer)
- Set `type: 'single'` in the question object
- Users can only select one answer
- Radio buttons are automatically used

### 2. Multiple Answer
- Set `type: 'multiple'` in the question object
- Users can select multiple answers
- Checkboxes are automatically used
- Badge showing "(Chọn nhiều đáp án)" is displayed

### 3. Scoring System
- Automatic scoring when user clicks "Nộp bài" (Submit)
- Displays:
  - Correct answers count
  - Total questions
  - Percentage score
  - Performance message based on score

### 4. Visual Feedback
- **Green border & background**: Correct answer
- **Red border & background**: Incorrect answer
- **Yellow border & background**: Should have been selected
- **Blue background**: User's selection

### 5. Explanations
- Optional `explanation` field in each question
- Displayed after submission
- Supports rich content (markdown, HTML)

## Score Messages

The component displays different messages based on performance:
- **90-100%**: "Xuất sắc! Bạn đã nắm vững kiến thức này."
- **70-89%**: "Tốt! Bạn đã hiểu khá rõ nội dung này."
- **50-69%**: "Khá ổn, nhưng hãy ôn tập thêm nhé."
- **Below 50%**: "Hãy xem lại và ôn tập thêm kiến thức này."

## Styling

The component uses CSS variables that integrate with Astro Starlight theme:
- `--sl-color-accent`: Accent color
- `--sl-color-text`: Text color
- `--sl-color-white`: White background
- `--sl-color-gray-*`: Gray scale colors

## Example Use Cases

### 1. Educational Content
```astro
<Quiz 
  title="Chapter 1 Review Quiz"
  questions={chapter1Questions} 
/>
```

### 2. Knowledge Check
```astro
<Quiz 
  title="Quick Knowledge Check"
  questions={quickCheckQuestions} 
/>
```

### 3. Assessment
```astro
<Quiz 
  title="Final Assessment"
  questions={assessmentQuestions} 
/>
```

## Notes

- The component is fully self-contained
- No external dependencies required
- Works with server-side rendering
- Accessible with keyboard navigation
- Mobile-friendly design
