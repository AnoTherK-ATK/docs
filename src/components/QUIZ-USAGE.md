# Quiz Component - Quick Usage Guide

## Quick Start

```astro
---
import Quiz from '@components/Quiz.astro';
---

<Quiz 
  title="My Quiz"
  questions={[
    {
      id: 'q1',
      type: 'single', // single answer
      question: 'What is 2+2?',
      options: [
        { id: 'a', text: '3' },
        { id: 'b', text: '4' }
      ],
      correctAnswers: ['b'],
      explanation: '2+2 equals 4'
    },
    {
      id: 'q2',
      type: 'multiple', // multiple answers
      question: 'Which are colors?',
      options: [
        { id: 'a', text: 'Red' },
        { id: 'b', text: 'Python' }
      ],
      correctAnswers: ['a'],
      explanation: 'Red is a color'
    }
  ]}
/>
```

## Question Types

### Single Answer (Radio)
```js
{
  type: 'single',
  correctAnswers: ['b']  // Only one answer
}
```

### Multiple Answer (Checkbox)
```js
{
  type: 'multiple',
  correctAnswers: ['a', 'c', 'd']  // Multiple answers
}
```

## Visual Feedback

- 🟢 **Green**: Correct answer
- 🔴 **Red**: Incorrect answer  
- 🟡 **Yellow**: Should have selected this
- 🔵 **Blue**: Your selection

## Result Messages

- 90-100%: "Xuất sắc! Bạn đã nắm vững kiến thức này."
- 70-89%: "Tốt! Bạn đã hiểu khá rõ nội dung này."
- 50-69%: "Khá ổn, nhưng hãy ôn tập thêm nhé."
- Below 50%: "Hãy xem lại và ôn tập thêm kiến thức này."

## Tips

- Add `explanation` for better learning experience
- Use meaningful IDs for questions and options
- Mix single and multiple answer questions
- Test on mobile devices

