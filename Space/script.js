const config = {
  type: 'radar',
  data: data,
  options: {
    elements: {
      line: {
        borderWidth: 3
      }
    }
  },
};



const data = {
    labels: [
      'Specific Energy',
      'Specific Power',
      'Safety',
      'Performance',
      'Life Span',
      'Cost',
    ],
    datasets: [{
      label: 'Lithium-Nickel-Cobalt-Aluminium (NCA)',
      data: [100, 100, 30, 90, 95, 50],
      fill: true,
      backgroundColor: 'rgba(255, 99, 132, 0.2)',
      borderColor: 'rgb(255, 99, 132)',
      pointBackgroundColor: 'rgb(255, 99, 132)',
      pointBorderColor: '#fff',
      pointHoverBackgroundColor: '#fff',
      pointHoverBorderColor: 'rgb(255, 99, 132)'
    }]
  };

  const config = {
    type: 'radar',
    data: data,
    options: {
      elements: {
        line: {
          borderWidth: 3
        }
      }
    },
  };