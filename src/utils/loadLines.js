export const loadLines = (raw, start, end) => {
  return raw.split('\n').slice(start - 1, end).join('\n');
};
